#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>





using namespace std;

class sfLine : public sf::Drawable
{
public:
    sfLine(const sf::Vector2f& point1, const sf::Vector2f& point2, sf::Color color_ = sf::Color::Black, float thick = 5.f):
        color(color_), thickness(thick)
    {
        sf::Vector2f direction = point2 - point1;
        sf::Vector2f unitDirection = direction/std::sqrt(direction.x*direction.x+direction.y*direction.y);
        sf::Vector2f unitPerpendicular(-unitDirection.y,unitDirection.x);

        sf::Vector2f offset = (thickness/2.f)*unitPerpendicular;

        vertices[0].position = point1 + offset;
        vertices[1].position = point2 + offset;
        vertices[2].position = point2 - offset;
        vertices[3].position = point1 - offset;

        for (int i=0; i<4; ++i)
            vertices[i].color = color;
    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(vertices,4,sf::Quads);
    }


public:
    sf::Vertex vertices[4];
    float thickness;
    sf::Color color;
};


pair<sf::Vector2f, sf::Vector2f> get_Line_from_equ(long double a, long double b, long double c){

    long double  pseudo_inf = 1e5;
    if (abs(a) < 0.0001 ){
        if (abs(b) < 0.0001){
            std::cerr << "Equation cannot be a form of 0x + 0y";
            exit(-1);
        }

        long double y_1 = (-a*pseudo_inf - c) / b;
        long double y_2 = (-a*(-pseudo_inf) - c) / b;

        return {{pseudo_inf, -y_1},{-pseudo_inf, -y_2,}};

    }

    long double x_1 = (-b*pseudo_inf - c) / a;
    long double x_2 = (-b*(-pseudo_inf) - c) / a;

    return {{x_1,-pseudo_inf},{x_2,-(-pseudo_inf)}};
}

vector<vector<long double>> equations_input;

vector<long double> target_function; /// 2x1 + 5x2 -> max


sfLine get_line(const vector<long double>& equation, sf::Color clr = sf::Color::Red){
    auto p = get_Line_from_equ(equation[0], equation[1], -equation[2]);

    return sfLine (p.first, p.second, clr, 0.25); /// 2x1 + 5x2 -> max <=>
}

sfLine get_contour_line(double F_value, sf::Color clr = sf::Color::Red){
    auto p = get_Line_from_equ(target_function[0], target_function[1], -F_value);

    return sfLine (p.first, p.second, clr, 0.15); /// 2x1 + 5x2 -> max <=>
}


double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double dist(const sf::Vector2f& vec){
    return dist(0,0, vec.x, vec.y);
}


// LINE/LINE
pair<bool, sf::Vector2f> lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {

    // calculate the direction of the lines
    float uA = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
    float uB = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));

    // if uA and uB are between 0-1, lines are colliding
    if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {

        // optionally, draw a circle where the lines meet
        float intersectionX = x1 + (uA * (x2-x1));
        float intersectionY = y1 + (uA * (y2-y1));

        return {true, {intersectionX, intersectionY}};
    }
    return {false, {-1,-1}};
}

struct geom_line{
    long double x1, y1, x2, y2;
};

long double min_ = 1e10; sf::Vector2f min_point = {-1,-1};
long double max_ = -1e10; sf::Vector2f max_point = {-1,-1};

vector<sf::Vector2f> convex_points;

bool check_point(const sf::Vector2f& point){

    long double value = point.x * target_function[0] + point.y * target_function[1];

    for(auto equation : equations_input){
        long double check_value = point.x * equation[0] + point.y * equation[1];
        if (!(check_value - 0.001 <= equation[2]) || point.x < 0 || point.y < 0 ){
            return false;
        }
    }

    if (value < min_){
        min_ = value;
        min_point = point;
    }

    if (value > max_){
        max_ = value;
        max_point = point;
    }

    convex_points.push_back(point);

    return true;
}


int orientation(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<sf::Vector2f>& a, bool include_collinear = false) {
    sf::Vector2f p0 = *min_element(a.begin(), a.end(), [](sf::Vector2f a, sf::Vector2f b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const sf::Vector2f& a, const sf::Vector2f& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<sf::Vector2f> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    a = st;
}



class Car;
class TrafficLight : public sf::Drawable{
public:

    sf::RectangleShape area = sf::RectangleShape({10,10});
    int ticks_cycle = 100;
    int ticks = 0;

    bool isSmart = false;
    int registered1 = 0;
    int registered2 = 0;


    TrafficLight(const sf::Vector2f& pos = {100,100}, bool _isSmart = false){
        area.setPosition(pos.x-5,pos.y-5);
        isSmart = _isSmart;
    }

    string state = "red";

    int road1_proportion = 30; /// 10-50


    int green1_start = 0;
    int green1_end = 30;

    int green2_start = 50;
    int green2_end = 80;

    void register_car(int type){
        if (type == 1) ++registered1;
        if (type == 2) ++registered2;
    }

    void update(){
        ticks = (ticks + 1) % ticks_cycle;

        if (ticks == 99 && isSmart){
            /// recalculate timings;
            double density1 = (double)(registered1) / (road1_proportion + 15);
            double density2 = (double)(registered2) / (60 - road1_proportion + 15 );

            if (density2 / 1.1 > density1){
                road1_proportion -= 5;
            }

            if (density2 / 1.4 > density1){
                road1_proportion -= 5;
            }

            if (density2 / 1.7 > density1){
                road1_proportion -= 5;
            }

            if (density1 / 1.1 > density2){
                road1_proportion += 5;
            }

            if (density1 / 1.4 > density2){
                road1_proportion += 5;
            }

            if (density1 / 1.7 > density2){
                road1_proportion += 5;
            }

            road1_proportion = max(10, road1_proportion);
            road1_proportion = min(50, road1_proportion);
            cout << "New proportion " << road1_proportion << endl;

            registered1 = 0;
            registered2 = 0;
        }

        sf::Color clr = sf::Color::White;


        if (allowed1()){
            clr = sf::Color::Green;
        }

        if (allowed2()){
            clr = sf::Color::Red;
        }

        clr.a = 40;

        area.setFillColor(clr);
    }

    bool allowed1(){
        return ticks > green1_start && ticks < road1_proportion;
    }

    bool allowed2(){
        return ticks > road1_proportion + 20 && ticks < green2_end;
    }

    bool allowed(int type){
        if (type == 1) return allowed1();
        if (type == 2) return allowed2();
        return false;
    }


    friend bool operator<(const TrafficLight& one, const TrafficLight& other){
        if (one.area.getSize().x != other.area.getSize().x) return one.area.getSize().x < other.area.getSize().x;
        if (one.area.getSize().y != other.area.getSize().y) return one.area.getSize().y < other.area.getSize().y;
        if (one.area.getPosition().x != other.area.getPosition().x) return one.area.getPosition().x < other.area.getPosition().x;
        if (one.area.getPosition().y != other.area.getPosition().y) return one.area.getPosition().y < other.area.getPosition().y;
        return false;
    }


private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {


        target.draw(area);
    }
};


vector<Car> cars;
vector<TrafficLight> traffics;


bool CircleToManyCircle(vector<sf::Vector2f> poses, sf::Vector2f position, float radius){

    int count = 0;
    for(int i = 0; i < poses.size(); ++i){
        if (dist( poses[i] - position ) < radius) ++count ;
    }

    return count > 1;

}

bool RectToPoint(sf::RectangleShape r, sf::Vector2f point){
    return (point.x >= r.getPosition().x && point.x <= r.getPosition().x+r.getSize().x &&
        point.y >= r.getPosition().y && point.y <= r.getPosition().y+r.getSize().y);
}

const float eps = 0.001;
class Car : public sf::Drawable{
public:

    vector<sf::Vector2f> path;
    sf::Vector2f position = {0,0};
    float Speed = 1;
    sf::Color color;
    float radius = 1;
    int current_road_type = 1;

    int path_progress;
    set<TrafficLight> ignore_list;


    Car(vector<sf::Vector2f> _path, sf::Vector2f _position, float _Speed = 1,
    sf::Color _color = sf::Color::Red, int _current_road_type = 1){
        path = _path;
        position = _position;
        path_progress = 0;
        Speed = _Speed;
        color = _color;
        current_road_type = _current_road_type;
    }

    string update(){

        sf::Vector2f deltaVec = -position + path[path_progress];
        deltaVec.x = max(-Speed, min(deltaVec.x, Speed));
        deltaVec.y = max(-Speed, min(deltaVec.y, Speed));

        sf::Vector2f new_position = position + deltaVec;

        vector<sf::Vector2f> poses;

        for(int i = 0; i < cars.size(); ++i){
            poses.push_back(cars[i].position);
        } // this is bad

        if (CircleToManyCircle(poses, new_position, 3*radius)) return "next_car_brake";

        for(int i = 0; i < traffics.size(); ++i){

            if ( RectToPoint(traffics[i].area, new_position)){

                if (ignore_list.find(traffics[i]) != ignore_list.end() ){
                    continue;
                }

                if (traffics[i].allowed(current_road_type)){
                    ignore_list.insert(traffics[i]);
                    traffics[i].register_car(current_road_type);
                }else{
                    return "brake_traffic";
                }
            }
        }

        position = new_position;

        if ( dist(position - path[path_progress]) < eps ){
            path_progress += 1;
        }

        if (path_progress == path.size()){
            return "delete";
        }

        return "normal";
    }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        sf::CircleShape cs(radius);
        cs.setPosition(position - sf::Vector2f(radius, radius));
        cs.setFillColor(color);
        target.draw(cs);
    }

};



int main() {


    sf::RenderWindow window(sf::VideoMode(800, 800), "Plot");

    ///sfLine O1({0,0}, {0,10 + 2.5}, sf::Color::Black, 5);
    ///sfLine O2({0,10}, {10 + 2.5,10}, sf::Color::Black, 5);
    ///sfLine O3({10,10}, {10,30}, sf::Color::Black, 5);

    sfLine O1({100,0}, {100,200}, sf::Color::Black, 5);
    sfLine O2({0,100}, {200,100}, sf::Color::Black, 5);

    sfLine O3({400,0}, {400,200}, sf::Color::Black, 5);
    sfLine O4({300,100}, {500,100}, sf::Color::Black, 5);

    traffics.push_back(TrafficLight({100,100}, false));
    traffics.push_back(TrafficLight({400,100}, true));






    sf::View view(sf::Vector2f(100.f, 100.f), sf::Vector2f(100.f, 100.f));
    window.setView(view);
    window.setFramerateLimit(120);

    int ticks = 0;
    int road_density = 7;

    while (window.isOpen()) {

        ticks += 1;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if(event.type == sf::Event::MouseWheelMoved)
            {
                double scale_factor = 0.9;
                for(int i = 0; i < abs(event.mouseWheel.delta); ++i){
                    if (event.mouseWheel.delta >= 0)
                        view.zoom(scale_factor);
                    else
                        view.zoom(1 / scale_factor);
                }
                window.setView(view);

            }
        }


        int dx = 0;
        int dy = 0;
        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::W)) dy -= 1;
        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::S)) dy += 1;

        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::A)) dx -= 1;
        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::D)) dx += 1;

        view.setCenter(view.getCenter() + sf::Vector2f(dx,dy) * (view.getSize().x) * 0.03f );
        window.setView(view);

        window.clear(sf::Color::White);


        if (ticks % 1000 == 0){
            road_density = 10 - road_density;
            cout << "New road density " << road_density << endl;
        }

        if (ticks % 10 == 0){

            vector<sf::Vector2f> poses;

            for(int i = 0; i < cars.size(); ++i){
                poses.push_back(cars[i].position);
            } // this is bad

            if (rand() % 10 < road_density){
                //cars.push_back(Car({ {0,40} }, {0,0}, 0.5, sf::Color::Blue, 2  ));

                if (!CircleToManyCircle(poses, {100,0}, 5*1))
                    cars.push_back(Car({ {100,200} }, {100,0}, 0.5,  sf::Color::Blue, 2  ));

                if (!CircleToManyCircle(poses, {400,0}, 5*1))
                    cars.push_back(Car({ {400,200} }, {400,0}, 0.5,  sf::Color::Blue, 2  ));
            }else{
                if (!CircleToManyCircle(poses, {0,100}, 5*1))
                    cars.push_back(Car({ {200,100} }, {0,100}  ));

                if (!CircleToManyCircle(poses, {300,100}, 5*1))
                    cars.push_back(Car({ {500,100} }, {300,100}  ));
            }
        }
        ///cout << "sz " << cars.size() << endl;;


        vector<Car> cars2;
        for (int i = 0; i < cars.size(); ++i){
            string ret_code = cars[i].update();
            if (ret_code != "delete"){
                cars2.push_back(cars[i]);
            }
        }

        for(int i = 0; i < traffics.size(); ++i){
            traffics[i].update();
        }

        cars = cars2;

        window.draw(O1);
        window.draw(O2);
        window.draw(O3);
        window.draw(O4);

        for(const Car& car : cars){
            window.draw(car);
        }

        for(const TrafficLight& traf : traffics){
            window.draw(traf);
        }

        window.display();
    }

    return 0;
}

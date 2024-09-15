#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <iomanip>
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

/// ax + by + c = 0 <=> sfLine (-y, т.к. в sfml Oy перевёрнута)
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
vector<sf::RectangleShape> allowed_area;


long double F_value = 0;

sfLine get_line(const vector<long double>& equation, sf::Color clr = sf::Color::Red){
    auto p = get_Line_from_equ(equation[0], equation[1], -equation[2]);

    return sfLine (p.first, p.second, clr, 0.25); /// 2x1 + 5x2 -> max <=>
}

sfLine get_contour_line(sf::Color clr = sf::Color::Red){
    auto p = get_Line_from_equ(target_function[0], target_function[1], -F_value);

    return sfLine (p.first, p.second, clr, 0.25); /// 2x1 + 5x2 -> max <=>
}

void populate_area(){
    allowed_area.clear();

    long double size = 0.2;
    for(long double x = 0; x < 10; x += size){
        for(long double y = 0; y < 10; y += size){
            bool ok = true;

            for(auto equation : equations_input){
                if (!(x * equation[0] + y * equation[1] <= equation[2])){
                    ok = false;
                    break;
                }
            }

            if (ok){
                sf::RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f(size, size));
                rectangle.setPosition(x - size / 2, -y - size / 2);
                rectangle.setFillColor(sf::Color::Green);
                allowed_area.push_back(rectangle);
            }
        }
    }
}


double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}


// LINE/LINE
bool lineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {

    // calculate the direction of the lines
    float uA = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
    float uB = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));

    // if uA and uB are between 0-1, lines are colliding
    if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {

        // optionally, draw a circle where the lines meet
        float intersectionX = x1 + (uA * (x2-x1));
        float intersectionY = y1 + (uA * (y2-y1));

        return true;
    }
    return false;
}

bool lineRect(float x1, float y1, float x2, float y2, float rx, float ry, float rw, float rh) {

    // check if the line has hit any of the rectangle's sides
    // uses the Line/Line function below
    bool left =   lineLine(x1,y1,x2,y2, rx,ry,rx, ry+rh);
    bool right =  lineLine(x1,y1,x2,y2, rx+rw,ry, rx+rw,ry+rh);
    bool top =    lineLine(x1,y1,x2,y2, rx,ry, rx+rw,ry);
    bool bottom = lineLine(x1,y1,x2,y2, rx,ry+rh, rx+rw,ry+rh);

    // if ANY of the above are true, the line
    // has hit the rectangle
    if (left || right || top || bottom) {
        return true;
    }
    return false;
}

pair<bool, sf::Vector2f> check_collision(){
    //cout << "h1" << endl;
    auto p = get_Line_from_equ(target_function[0], target_function[1], -F_value);

    //cout << "h2" << endl;
    int cou = 0;
    for(auto shape : allowed_area){
        if (lineRect(p.first.x, p.first.y, p.second.x, p.second.y,
            shape.getPosition().x, shape.getPosition().y, shape.getSize().x, shape.getSize().y ) ){
                sf::Vector2f pos = shape.getPosition() - sf::Vector2f(shape.getSize().x / 2, shape.getSize().y / 2);
                pos.y *= -1;
                return {1,pos};
        }

    }
    return {false, sf::Vector2f(-1,-1)};

}

int main() {

    target_function = {2,5,0};
    equations_input.push_back({1,2,8});
    equations_input.push_back({1,1,6});
    equations_input.push_back({-1,-3,-3});


    populate_area();

    sf::RenderWindow window(sf::VideoMode(800, 600), "Plot");

    sfLine Oy({0,1e10}, {0,-1e10}, sf::Color::Black, 0.25);
    sfLine Ox({1e10,0}, {-1e10,0}, sf::Color::Black, 0.25);

    sf::View view(sf::Vector2f(4.f, -4.f), sf::Vector2f(10.f, 10.f));
    window.setView(view);
    window.setFramerateLimit(20);

    cout << "h0" << endl;

    long double min_ = 1e10; sf::Vector2f min_point = {-1,-1};
    long double max_ = -1e10; sf::Vector2f max_point = {-1,-1};

    long double start = -10;
    long double end = 50;

    long double step = 1;
    long double calculations_per_frame = 100;
    bool finished_calculations = false;

    F_value = start;

    while (window.isOpen()) {
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

        //cout << "h0.5" << endl;



        if (F_value < end){
            for(int calculations = 0; calculations < calculations_per_frame; ++calculations){
                F_value += step / calculations_per_frame;
                if (check_collision().first){
                    if (F_value < min_){
                        min_ = F_value;
                        min_point = check_collision().second;
                    }

                    if (F_value > max_){
                        max_ = F_value;
                        max_point = check_collision().second;
                    }
                }
            }
        }else{
            if (!finished_calculations){

                long double new_min = target_function[0] * min_point.x + target_function[1] * min_point.y;
                long double new_max = target_function[0] * max_point.x + target_function[1] * max_point.y;


                cout << fixed << setprecision(3) << "F_min: " << new_min << " at " << min_point.x << " " << min_point.y << endl;
                cout << fixed << setprecision(3) << "F_max: " << new_max << " at " << max_point.x << " " << max_point.y << endl;
                finished_calculations = true;
            }

        }





        window.clear(sf::Color::White);

        for(auto circle : allowed_area){
            window.draw(circle);
        }

        window.draw(Ox);
        window.draw(Oy);
        window.draw(get_contour_line());

        for(auto equation : equations_input){
            window.draw(get_line(equation, sf::Color::Blue));
        }

        window.display();
    }

    return 0;
}

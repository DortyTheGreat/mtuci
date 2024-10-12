#define SFML_STATIC
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

/// ax + by + c = 0 <=> sfLine (-y, ò.ê. â sfml Oy ïåðåâ¸ðíóòà)
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



int main() {

    /**
    /// Çàäàíèå a (Âàðèàíò 16)
    target_function = {2,5};
    equations_input.push_back({1,2,8});
    equations_input.push_back({1,1,6});
    equations_input.push_back({-1,-3,-3});
    */

    /**
    /// Âàðèàíò 16, á
    target_function = {1,3};

    equations_input.push_back({1,1,8});
    equations_input.push_back({1,3,6});
    equations_input.push_back({-1,-3,-3});
    */

    /**
    /// Âàðèàíò 16, â
    target_function = {1,3};

    equations_input.push_back({-1,-2,-9});
    equations_input.push_back({-1,-4,-8});
    equations_input.push_back({-2,-1,-3});
    */


    /// Âàðèàíò 16, ã
    target_function = {-5,3};

    equations_input.push_back({1,2,10});
    equations_input.push_back({3,1,6});
    equations_input.push_back({-1,-1,-16});


    vector<geom_line> lines;




    for(auto equation : equations_input){
        auto p = get_Line_from_equ(equation[0], equation[1], -equation[2]);
        lines.push_back({p.first.x, -p.first.y, p.second.x, -p.second.y});

    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Plot");

    sfLine Oy({0,1e10}, {0,-1e10}, sf::Color::Black, 0.25);
    sfLine Ox({1e10,0}, {-1e10,0}, sf::Color::Black, 0.25);

    lines.push_back({0,1e10,0,-1e10});
    lines.push_back({1e10,0,-1e10,0});

    vector<sf::Vector2f> intersec_points;

    for(int i = 0; i < lines.size(); ++i){
        for(int j = i + 1; j < lines.size(); ++j){
            auto collision_res = lineLine(lines[i].x1,lines[i].y1,lines[i].x2,lines[i].y2,lines[j].x1,lines[j].y1,lines[j].x2,lines[j].y2);
            if (collision_res.first){
                intersec_points.push_back(collision_res.second);
            }
        }
    }

    bool is_there_solution = false;
    for(auto point : intersec_points){
        is_there_solution |= check_point(point);
    }

    if (!is_there_solution){
        cout << "Solution does not exist" << endl;
    }

    long double min_pre = min_;
    long double max_pre = max_;

    for(auto equation : equations_input){
        auto p = get_Line_from_equ(equation[0], equation[1], -equation[2]);
        check_point({p.first.x, -p.first.y});
        check_point({p.second.x, -p.second.y});
    }

    check_point({0,1e10});
    check_point({0,-1e10});
    check_point({1e10,0});
    check_point({-1e10,0});



    bool unbound_min = false;
    bool unbound_max = false;

    if (min_pre != min_){
        cout << "Solution isn't bounded to min" << endl;
        unbound_min = true;
    }

    if (max_pre != max_){
        cout << "Solution isn't bounded to max" << endl;
        unbound_max = true;
    }

    if (!unbound_min && is_there_solution){
        cout << fixed << setprecision(3) << "F_min: " << min_ << " at (" << min_point.x << " " << min_point.y << ")" << endl;
    }

    if (!unbound_max && is_there_solution){
        cout << fixed << setprecision(3) << "F_max: " << max_ << " at (" << max_point.x << " " << max_point.y << ")" << endl;
    }

    sf::ConvexShape Polygon;

    Polygon.setPointCount(convex_points.size());
    Polygon.setFillColor(sf::Color::Green);
    if (convex_points.size() >= 3){

        convex_hull(convex_points, false);

        Polygon.setPointCount(convex_points.size());

        int cou = 0;
        for(auto point : convex_points){
            Polygon.setPoint(cou++, sf::Vector2f(point.x, -point.y));
        }
    }





    sf::View view(sf::Vector2f(4.f, -4.f), sf::Vector2f(10.f, 10.f));
    window.setView(view);
    window.setFramerateLimit(20);

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


        int dx = 0;
        int dy = 0;
        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::W)) dy -= 1;
        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::S)) dy += 1;

        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::A)) dx -= 1;
        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Key::D)) dx += 1;

        view.setCenter(view.getCenter() + sf::Vector2f(dx,dy) * (view.getSize().x) * 0.03f );
        window.setView(view);

        window.clear(sf::Color::White);

        window.draw(Polygon);

        window.draw(Ox);
        window.draw(Oy);
        //window.draw(get_contour_line());

        for(auto equation : equations_input){
            window.draw(get_line(equation, sf::Color::Blue));
        }

        if (!unbound_max && is_there_solution){
            window.draw(get_contour_line(max_, sf::Color::Red));
        }

        if (!unbound_min && is_there_solution){
            window.draw(get_contour_line(min_, sf::Color::Magenta));
        }



        window.display();
    }

    return 0;
}

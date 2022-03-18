#include "Simple_window.h"
#include "Graph.h"
#include <iostream>

double one(double x){ return 1; }
double slope(double x) { return x/ 2; }
double square(double x) { return x* x; }
double sloping_cos(double x){ return cos(x)+ slope(x); }

int main()
{
	Simple_window win {Point{100, 100}, 600, 600, "Function graphs"};

    Axis x {Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
    Axis y {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);

    constexpr int min = -10;
    constexpr int max = 11;
    const Point orig {300,300};
    constexpr int num = 400;
    constexpr int xscale = 20;
    constexpr int yscale = 20;

    Function f1 (one,min,max,orig,num,xscale,yscale);
    Function f2 (slope,min,max,orig,num,xscale,yscale);
    Text label_f2(Point(100, 300- (-10* 20/ 2)),"x/2");
    Function f3 (square,min,max,orig,num,xscale,yscale);
    Function f4 (cos,min,max,orig,num,xscale,yscale);
    f4.set_color(Color::blue);  
    Function f5 (sloping_cos,min,max,orig,num,xscale,yscale);

    window.attach(f1);
    window.attach(f2);
    window.attach(label_f2);
    window.attach(f3);
    window.attach(f4);
    window.attach(f5);
    window.wait_for_button();


    return 0;
}
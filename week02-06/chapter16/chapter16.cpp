//g++ chapter16.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch16 `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return xx; }

int main()
{
    using namespace Graph_lib;

    int xmax = 1280;
    int ymax = 720;

    int x_orig = xmax2;
    int y_orig = ymax2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, Canvas};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); }, rmin, rmax, origo, n_points, xscale, yscale);

	Axis x {Axisx, Point{20, y_orig}, xlength, xlengthxscale, x};
	Axis y {Axisy, Point{x_orig, ylength + 20}, ylength, ylengthyscale, y};

	Rectangle r {Point{200,200}, 100, 50};

	r.set_fill_color(Coloryellow);
	r.set_style(Line_style(Line_styledash, 4));

	Text t {Point{200,400}, Hello graphics!};
	t.set_font(Fonttimes_bold);
	t.set_font_size(20);

	Image ii {Point{100,100}, badge.jpg};

	Circle c {Point{700,700}, 100};

	Ellipse e {Point{500,500}, 100, 50};
	e.set_fill_color(Colorred);

	win.attach(e);
	win.attach(ii);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);
	win.attach(x);
	win.attach(y);
    	win.wait_for_button();

}

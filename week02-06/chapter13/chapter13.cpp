#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
{	
	try{ 

		Point t1{300,50};
		Simple_window win(t1,1000,800,"My window");
		win.wait_for_button();
		//1. drill

		Lines grid;
		int x_size = 800;
		int y_size = 800;
		for(int i=100; i<=x_size; i+=100)
		{
			grid.add(Point(i, 0), Point(i, y_size));
			grid.add(Point(0, i), Point(x_size, i));
		}
		win.attach(grid);
		win.wait_for_button();
		//2.

		Vector_ref<Rectangle> rect;
	    for(int i=0; i<8; ++i)
	    {
		    rect.push_back(new Rectangle{Point{i*100,i*100},100, 100});
		    rect[i].set_fill_color(Color::red);
		    rect[i].set_color(Color::invisible);
		    win.attach(rect[i]);
		}
		//3.

		Image img0 (Point{0, 300}, "bread.jpg");
        Image img1 (Point{300, 500}, "bread.jpg");
        Image img2 (Point{500, 100}, "bread.jpg");
        img0.set_mask(Point{0,0},200,200);
	    img1.set_mask(Point{0,0},200,200);
	    img2.set_mask(Point{0,0},200,200);
        win.attach(img0);
        win.attach(img1);
        win.attach(img2);

        win.wait_for_button();
		//4. badge1.set_mask(Point(xy),x,y)

		Image mvpic {Point{0,0}, "clown.jpg"};
	    mvpic.set_mask(Point{0,0},100,100);
	    win.attach(mvpic);
	    win.wait_for_button();
    
	    for(int i=0; i<8; ++i)
	    {   
	        for(int j=0; j<8; ++j)
	        {
	            mvpic.move(100, 0);
	            win.wait_for_button();
        	}
	        mvpic.move(-800, 100);      
	        win.wait_for_button();
        }
		//5. badge (gui mappaba) itt is setmask .move() fgv helyezget

	}catch (exception& e) { 
			cerr << "exception: " << e.what()<< '\n';
			return 1;
		} catch (...) { 
			cerr << "error\n"; 
			return 2;

	}
}

#include "GUI.h"
#include "Lines_window.h"

int main(){
	try{
		Lines_window win(Point(100,100), 1000, 800,"lines");
    return gui_main();
	}
	catch(exception& e) {
    cerr << "Exception: " << e.what() << '\n';
    return 1;
}
    catch (...) {
    cerr << "Some exception\n";
return 2;
}
}
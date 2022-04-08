#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<stdexcept>
#include<list>
#include<algorithm>

template<typename C>
void print_contents(const C& c){
	for(auto& a: c)
		std::cout<<a<<' ';
	std::cout<<std::endl;
}

template<typename C>
void inc_contents(C& c, int n = 1){
	for(auto& a: c)
	{
		a += n;
	}
}

template<typename Iter1, typename Iter2>
// request Input_iterator<Iter1>() && Output_isterator<Iter2>()
Iter2 ora_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p= f1; p!=e1; ++p){
		*f2++= *p;
		//f2++
	}
	return f2;
}
int main()
try{
	constexpr int size = 10;

	int arr[size];
	for (int i=0; i<size; ++i) arr[i]=i;

		std::array<int, size> ai;
		std::copy(arr, arr+size, ai.begin());
		std::cout<< "C array: \t";
		print_contents(ai);

		std::vector<int> vi(size);
		std::copy(arr, arr+size, vi.begin());
		std::cout<< "C vector: \t";
		print_contents(vi);

		std::list<int> li(size);
		std::copy(arr, arr+size, li.begin());
		std::cout<< "C list: \t";
		print_contents(li);
		std::cout<< "\n";

		std::array<int, size> ai2= ai;
		std::vector<int> vi2= vi;
		std::list<int> li2= li;

		std::cout<<"array copy: \t"; print_contents(ai2);
		std::cout<<"vector copy: \t"; print_contents(vi2);
		std::cout<<"list copy: \t"; print_contents(li2);
		std::cout<<"\n";

		inc_contents(ai2, 2);
		inc_contents(vi2, 3);
		inc_contents(li2, 5);

		std::cout<<"array increazed: \t"; print_contents(ai2);
		std::cout<<"vector increazed: \t"; print_contents(vi2);
		std::cout<<"list increazed: \t"; print_contents(li2);

		ora_copy(ai2.begin(), ai2.end(), vi2.begin());
		ora_copy(li2.begin(), li2.end(), ai2.begin());
		std::cout<<	"\n";

		
		std::cout<<"array copied: \t";print_contents(ai2);
		std::cout<<"vector copied: \t";print_contents(vi2);
		std::cout<<"list copied: \t";print_contents(li2);

		std::vector<int>::iterator vit;
	    vit = std::find(vi2.begin(), vi2.end(), 3);
	    if (vit != vi2.end())
	        std::cout << "Found at: " << std::distance(vi2.begin(), vit) << '\n';
	    else
	        std::cout << "Wasn't found\n";

	    std::list<int>::iterator lit;
	    lit = std::find(li2.begin(), li2.end(), 27);
	    if (lit != li2.end())
	        std::cout << "Found at: " << std::distance(li2.begin(), lit) << '\n';
	    else
	        std::cout << "Wasn't found\n";
}

catch(std::exception& e) {
	std::cerr<< "exception: "<<e.what()<<'\n';
	return 1;
}

catch(...) {
	std::cerr << "unknown exception \n";
	return 2;
}
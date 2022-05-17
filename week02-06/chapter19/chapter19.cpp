#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
struct S{
	S(T vv ) : val{vv} {} 

	T& get();
	const T& get() const;

	S& operator =(const T& vv);

	private: 
		T val;
};

template<typename T>
S<T>& S<T>::operator =(const T& s){
	val = s;
	return *this; 
}

template<typename T>
istream& operator >>(istream& is, vector<T>& v)
{
	v.clear();
	char ch = 0;
	for(T val; is >> val;)
	{
		v.push_back(val);
		is >> ch;
		if (ch != ';') break;
	}
	return is;
}

template<typename T>
void read_val(T& v){
	std::cin >> v;
}

template<typename T>
T& S<T>::get(){
	return val;
}

template<typename T> 
const T& S<T>::get() const{
	return val;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
	os << "{ ";
	for(int i=0; i< v.size(); ++i)
	{
		os <<v[i] << (i < v.size()-1 ? ", ": " ");
	}
	os << "}\n";
	return os;
}

int main(){
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {10.2};
	S<std::string> ss {"hello"};
	S<std::vector<int>> svi {std::vector<int>{1,10,100}};

	cout<< "S<int> : "<< si.get()<< endl;
	cout<< "S<char> : "<< sc.get()<< endl;
	cout<< "S<double> : "<< sd.get()<< endl;
	cout<< "S<string> : "<< ss.get()<< endl;
	  //<< "S<vector> : "<< svi.get()<< endl;

	cout<<"S<vector<int>> : ";
	for (auto& a: svi.get())
	{
		cout<< a <<' ';
	}
		cout<<endl;

	int ii;
	cout<<"int:"<<endl;
	read_val(ii);
	S<int> ii2 {ii};

	char cc;
	cout<<"char:"<<endl;
	read_val(cc);
	S<char> cc2 {cc};

	double dd;
	cout<<"double:"<<endl;
	read_val(dd);
	S<double> dd2 {dd};

	vector<int> vi;
	cout<<"vector separated by *space* and end it with \";\""<<endl;
	read_val(vi);
	S<vector<int>> vi2 {vi};

	cout<<"S<int> : "<<ii2.get()<<endl;
	cout<<"S<char> : "<<cc2.get()<<endl;
	cout<<"S<double> : "<<dd2.get()<<endl;
	cout<<"S<vector<int>>: "<<vi2.get() <<endl;
}

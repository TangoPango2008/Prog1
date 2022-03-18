#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

	class person{
		public:
				person(){}
				person(string f, string l, int a) :f{f}, l{l}, a{a}{
					if(a<0 || a>=150){
						throw runtime_error("invalid age");
					}
					for(int i = 0;l.length();i++){
						if(l[i] == ";", ":", "\"", "\'", "[", "]", "*", "&", "^", "%", "$", "@", "!"){
							throw runtime_error("invalid character in lastname");
						}break;
					}
				};
				string first() const {return f;}
				string last() const {return l;}
				int age() const {return a;}

		private:
				string f;
				string l;
				int a; 
	};


ostream& operator<<(ostream& os, const person& p)
{
	return os << p.first() << " " <<p.last() << " " << p.age();
}

istream& operator>>(instream& is, person& p)
{
	string f;
	string l;
	int a;

	is >> f >> l >> a;
	p = person(f, l, a);

	return is;
}


int main(){

	person p = person("Goofy","D", 63);
	//cout << p.name << " " << p.age << endl;
	cout << p << endl;
	person p2;
	cin >> p2;
	cout << p2 << endl;

	vector<person> vec;
	for(person p; cin >> p;){
		if(p.first() == "end" || p.last() == "end")break;
		vec.push_back(p);
	}

	for(Person p: vec)
		cout<< p << endl;


	return 0;
}







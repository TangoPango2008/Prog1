#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

	void error(string s)
	{
	    throw runtime_error(s);
	}

	struct person
	{
		person(){}
		person(string f, string l, int a) :f{f}, l{l}, a{a}
		{
			if(a<0 || a>=150)
			{
				throw runtime_error("invalid age");
			}
			string n = f + l;        
		    for (char c : n) {
		        switch(c)
		        {
		            case ';': case ':': case '"': 
		            case '[': case ']': case '*':
		            case '&': case '^': case '%': 
		            case '$': case '#': case '@':
		            case '!': error("person(): bad char in names");
		            break;
        		}
    }		};
		string first() const {return f;}
		string last() const {return l;}
		int age() const {return a;}

		private:
				string f;
				string l;
				int a; 
	};

istream& operator >>(istream& is, person& p)
{
	string f;
	string l;
	int a;

	is >> f >> l >> a;
	
	p = person(f, l, a);

	return is;
}


ostream& operator <<(ostream& os, const person& p)
{
	return os << p.first() << " " <<p.last() << " " << p.age();
}


int main(){

	person p = person("Goofy","D", 63);
	//cout << p.name << " " << p.age << endl;
	cout << p << endl;
	person p2;
	cin >> p2;

	vector<person> vec;
	for(person p; cin >> p;){
		if(p.first() == "end" || p.last() == "end")break;
		vec.push_back(p);
	}

	for(person p: vec)
		cout<< p << endl;


	return 0;
}







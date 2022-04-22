#include "../std_lib_facilities.h"
#include <fstream>

class lower {
    double v;
public:
    lower(double vv) : v{vv} { }

    bool operator()(const double val) { return val < v; }
};

int main(){
	vector<double> vd;
	ifstream ifile {"chapter21text2.txt"};
	for(float f; ifile >> f;) vd.push_back(f);
	
	cout << "Vd:\n";
	for (int i = 0; i < vd.size(); i++)
	{
		cout << vd[i] << endl;
	}

	vector<int> vi(vd.size());
	copy(vd.begin(),vd.end(),vi.begin());

	float fdouble = 0;
	float fint = 0;
	cout << "\nVd and Vi:\n";
	for (int i = 0; i < vi.size(); i++)
	{
		cout << "Vd[i]: " << vd[i] << "\tVi[i]: " << vi[i] << endl;
		fdouble += vd[i];
		fint += vi[i];
	}
	cout << "Sum of Vd: " << fdouble << endl;
	cout << "Difference between Vd and Vi: " << fdouble-fint << endl; 
	
	reverse(vd.begin(),vd.end());
	cout << "\nReversed Vd elements:\n";
	for (int i = 0; i < vd.size(); i++)
	{
		cout << vd[i] << endl;
	}
	sort(vd);
	cout << "\nSorted Vd elements:\n";
	for (int i = 0; i < vd.size(); i++)
	{
		cout << vd[i] << endl;
	}
	float mean_value = vd[vd.size()/2];
	cout << "\nMean value of Vd: " << mean_value << endl;

	vector<double> vd2(vd.size());	
	
	auto b = find_if(vd.begin(),vd.end(),
			[&](int e){return e > mean_value;});
	
	copy(vd.begin(),b,vd2.begin());
	
	auto a = find(vd2.begin(), vd2.end(), 0);
	vd2.erase(a,vd2.end());
	for (int i = 0; i < vd2.size(); i++)
	{
		cout << vd2[i] << endl;
	}
}
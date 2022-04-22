#include "../std_lib_facilities.h"
#include <map>

template<typename T>
void print(T v){
	for(auto& a : v)
		cout << a.first << ' ' << a.second << endl;
}
template<typename T1, typename T2>
istream& operator>>(istream& is, map<T1,T2> m){
	is >> m.fisrt >> m.second;
	return is;
}
int main(){
	map<string,int> msi;
	msi["Abcd"] = 10;
	msi["Bcde"] = 20;
	msi["Cdef"] = 30;
	msi["Defg"] = 40;
	msi["Efgh"] = 50;
	msi["Fghi"] = 60;
	msi["Ghij"] = 70;
	msi["Hijk"] = 80;
	msi["Ijkl"] = 90;
	msi["Jklm"] = 100;

	print(msi);
	msi.erase(msi.begin(),msi.end());
	print(msi);

	cout << "\ngive 10 pairs:\n";
	for (int i = 0; i < 10; i++)
	{
		string s; int ii;
		cin >> s >> ii;
		msi[s] = ii;
	}
	cout << "\nthe pairs:\n";
	print(msi);
	int sum = 0;
	for(auto& a : msi)
		sum +=  a.second;
	cout << "their sum: " << sum << endl;

	map<int,string> mis;

	for (const auto& a : msi)
        mis[a.second] = a.first;
    cout << "\nmirrored pairs:\n";
    print(mis);
}
#include "../std_lib_facilities.h"
#include <list>

struct Item{ 
	string name; 
	int iid; 
	double value;
};
istream& operator>>(istream& is, Item& it){
	is >> it.name >> it.iid >> it.value;
	Item{it.name,it.iid,it.value};
	return is;
}
struct sort_name{
	bool operator()(Item& it1, Item& it2)
			{ return it1.name < it2.name;}
};
struct sort_iid{
	bool operator()(Item& it1, Item& it2)
			{ return it1.iid < it2.iid;}
};
struct sort_value{
	bool operator()(Item& it1, Item& it2)
			{ return it1.value > it2.value;}
};
struct remove_name{
	string name;
public:
	remove_name(const string& na) : name(na) {}
	bool operator()(Item& it1){
		{return it1.name == name;}
	}
};
struct remove_iid{
	int iid;
public:
	remove_iid(const int& id) : iid(id) {}
	bool operator()(Item& it1){
		{return it1.iid == iid;}
	}
};
template<typename T>
void print(T v){
	for(auto& a : v)
		cout << a.name << ' ' << a.iid << ' ' << a.value << endl;
}

int main(){
	vector<Item> vi;
	ifstream ifile {"chapter21text.txt"};
	for(Item it; ifile >> it;){
		vi.push_back(it);
	}
	cout << "Before sort:\n";
	print(vi);

	sort(vi.begin(),vi.end(),sort_name());

	cout << "\nSort by name:\n";
	print(vi);

	sort(vi.begin(),vi.end(),sort_iid());
	cout << "\nSort by iid:\n";
	print(vi);

	sort(vi.begin(),vi.end(),sort_value());
	cout << "\nSort by value (desc):\n";
	print(vi);

	vi.push_back(Item {"horse shoe", 99,12.34}); 
	vi.push_back(Item {"Canon S400", 9988,499.95});
	cout << "\nAdded 2 rows:\n";
	print(vi);

	const auto& a = find_if(vi.begin(),vi.end(),remove_name("asd"));
	if(a != vi.end()) vi.erase(a);
	const auto& b = find_if(vi.begin(),vi.end(),remove_name("qwer"));
	if(b != vi.end()) vi.erase(b); 
	cout << "\nRemoved 2 rows by name:\n";
	print(vi);

	const auto& aa = find_if(vi.begin(),vi.end(),remove_iid(3));
	if(aa != vi.end()) vi.erase(aa);
	const auto& bb = find_if(vi.begin(),vi.end(),remove_iid(7));
	if(bb != vi.end()) vi.erase(bb);
	cout << "\nRemoved 2 rows by iid:\n";
	print(vi);

	const auto& aaa = find_if(vi.begin(),vi.end(),remove_iid(3));
	if(aaa != vi.end()) vi.erase(aaa);
	const auto& bbb = find_if(vi.begin(),vi.end(),remove_iid(7));
	if(bbb != vi.end()) vi.erase(bbb);
	cout << "\nRemoved 2 rows by iid (the same):\n";
	print(vi);

	ifile.close();
	list<Item> li;
	ifile.open("valami.txt");
	for(Item it; ifile >> it;) li.push_back(it);
	cout << "\nBefore sort: \n";
	print(li);

	li.sort(sort_name());
	cout << "\nSort by name: \n";
	print(li);

	li.sort(sort_iid());
	cout << "\nSort by iid: \n";
	print(li);

	li.sort(sort_value());
	cout << "\nSort by value (desc): \n";
	print(li);

	li.push_back(Item {"horse shoe", 99,12.34}); 
	li.push_back(Item {"Canon S400", 9988,499.95});
	cout << "\nAdded 2 rows: \n";
	print(li);
	
	const auto& al = find_if(li.begin(),li.end(),remove_name("asd"));
	if(al != li.end()) li.erase(al);
	const auto& bl = find_if(li.begin(),li.end(),remove_name("qwer"));
	if(bl != li.end()) li.erase(bl);
	cout << "\nErased 2 rows by name: \n";
	print(li);

	const auto& all = find_if(li.begin(),li.end(),remove_iid(3));
	if(all != li.end()) li.erase(all);
	const auto& bll = find_if(li.begin(),li.end(),remove_iid(7));
	if(bll != li.end()) li.erase(bll);
	cout << "\nErased 2 rows by iid: \n";
	print(vi);

}
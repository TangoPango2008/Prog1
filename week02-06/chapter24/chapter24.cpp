#include<iostream>
#include<iomanip>
#include<cmath>
#include<complex>
#include"../GUI/Matrix.h"
#include"../GUI/MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try{
	cout<<"sizeof:\n";
	cout<<"char\t"<<sizeof(char)<<'\n';
	cout<<"short\t"<<sizeof(short)<<'\n';
	cout<<"int\t"<<sizeof(int)<<'\n';
	cout<<"long\t"<<sizeof(long)<<'\n';
	cout<<"float\t"<<sizeof(float)<<'\n';
	cout<<"double\t"<<sizeof(double)<<'\n';
	cout<<"int*\t"<<sizeof(int*)<<'\n';
	cout<<"double*\t"<<sizeof(double*)<<'\n';

	cout<< "\nMatrix sizes:\n";
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10,10);
	Matrix<int, 3> e(10,10,10);
	cout<<"1D int, 10 elem \t\t"<<sizeof(a) << '\n';
	cout<<"1D int, 100 elem\t\t"<<sizeof(b) << '\n';
	cout<<"1D double, 10 elem\t\t"<<sizeof(c) << '\n';
	cout<<"2D int, 10x10 elem\t\t"<<sizeof(d) << '\n';
	cout<<"3D int, 10x10x10 elem\t\t"<<sizeof(e) << '\n';

	cout<<"\nNumber of elements:\n";
	cout<<"a:\t"<<a.size()<<'\n';
	cout<<"b:\t"<<b.size()<<'\n';
	cout<<"c:\t"<<c.size()<<'\n';
	cout<<"d:\t"<<d.size()<<'\n';
	cout<<"e:\t"<<e.size()<<'\n';

	int i;
	cout<<"Enter a number: ";
	while (i > 0)
	{
		if (i < 0) cout<<"No square root"<<'\n';
		else 
		{
			cout<<"square root: "<<sqrt(i)<<'\n';
			cout<<"Enter a number: ";
			cin>>i;
		}
	}
	
	cin.clear();
	cin.ignore();
	cout<< "Enter 10 floats:";
	Matrix<double> m(10);
	double d2;
	for(int i = 0; i<10; ++i){
		cin >>d2;
		if (!cin) throw runtime_error("Problem reading from cin");
		m[i] = d2;
	}
	cout<<"Matrix: \n"<< m<< '\n';

	cout << "\nMult. table\nEnter n: ";
	int n;
	cin >> n;
	cout <<"Enter m: ";
	int m2;
	cin >> m2;
	Matrix<int, 2> table(n+1,m2+1);
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0; j<= m2; j++){
			table(i,j) = i*j;
			cout<<table(i,j)<<" ";
		}
	cout<<'\n';
	}
	Matrix<complex<double>> m3(10);
	cout<<"\nEnter 10 complex numbers (Re,Im): ";
	complex<double> comp;
	for(int i = 0; i<10; i++){
		cin>>comp;
		if(!cin) throw runtime_error("Problem reading complex number!");
		m3[i] = comp;
	}
	cout<<m3;
	complex<double> sum;
	for(int i = 0;i<10;i++){
		sum += m3[i];
	}
	cout<<"Sum: "<< sum << '\n';

	Matrix<int, 2> m4(2,3);
	cout<<"\nEnter six ints:\n";
	int n2;
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++){
			cin >> n2;
			m4(i,j)=n2;
		}
	}
	cout<<"Matrix:\n"<<m4<<'\n';

}catch(exception& e) {
	cerr << "exception: " << e.what()<<'\n';
}catch(...) {
	cerr << "exception!\n";
}

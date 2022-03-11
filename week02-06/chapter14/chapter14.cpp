#include <stdlib.h>
#include <iostream>
using namespace std;

class B1{
	public: 
			virtual void vf() { cout<<"B1::vf()\n"; }
			void f() { cout<<"B1::f()\n"; }
			virtual void pvf() { cout<<"B1::pvf\n"; }
};

class D1: public B1{
	public:
			void vf() override{ cout<<"D1::fv()\n"; }
			void f() { cout<<"D1::f()\n"; }
};

class D2: public D1{
	public: 
		void pvf() override{ cout<<"D2::pvf()\n"; }
};

class B2: public B1{
	public:
		virtual void pvf(){ cout<<"B2::pvf()\n"; }
};

class D21: public B2{
	public:
		string data = "D21::data\n";
		void pvf() override { cout<<data<<'\n'; }
};

class D22: public B2{
	public:
		int data2 = 2;
		void pvf() override { cout<<data2<<'\n'; };

		void f(B2& b2){ b2.pvf(); }
};

int main(){
	B1 b1main;
	b1main.f();
	b1main.vf();
	b1main.pvf();

	D1 d1main;
	d1main.f();
	d1main.vf();
	d1main.pvf();

	B1& b1ref = d1main;
	b1ref.f();
	b1ref.vf();
	b1ref.pvf();

	D2 d2main;
	d2main.f();
	d2main.vf();
	d2main.pvf();

	D21 d21main;
	d21main.f();
	d21main.vf();
	d21main.pvf();

	B2 b2main;

	D22 d22main;
	d22main.f(b2main);
	d22main.vf();
	d22main.pvf();
}
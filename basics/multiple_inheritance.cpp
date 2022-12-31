// Multilevel inheritance and the diamond of death

#include<iostream>
using namespace std;

class BaseClass1{
	public:
		void fun1(){
			cout << "Fun 1 BaseClass 1" << endl;
		}
};


class BaseClass2{
	public:
		void fun1(){
			cout << "Fun2 BaseClass2" << endl;
		}
};

class DerivedClass : public BaseClass1, public BaseClass2{
	//we are inheriting from both base classes
	//public:
	//	void fun1(){
	//		cout << "Fun 3 Deerived Class" << endl;
	//	}
};

int main(){
	DerivedClass derived;
	derived.BaseClass1::fun1();
	//derived.fun2();
	//derived.fun3();
}

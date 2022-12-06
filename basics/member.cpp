#include<iostream>
#include<string>

using namespace std; 

class Rectangle {
	private: 
		int len, breadth; 
	public: 
		//setting defaults
		void set_dim(int l = 10, int b = 5){
			len = l; 
			breadth = b; 
		}

		double perimeter(); 

}; 

//defining method outside of class definition 
double Rectangle::perimeter(){
	return 2*(len + breadth); 
}
int main(){
	Rectangle rect; 
	rect.set_dim(); 
	cout << "perimeter = " << rect.perimeter() << endl; 

}

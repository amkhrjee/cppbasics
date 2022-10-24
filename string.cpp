#include<iostream>
#include<string>

using namespace std; 

int main() {
/*	double num; 
	string str; 

	cout << "Please enter a number: "<<endl; 
	cin >> num; 
	cout << "Enter your name: " << endl; 
	cin.ignore(1000, '\n');
//	cin.clear();
	getline(cin, str); 
	cout << "Your name is "<< str << endl;
*/
	string name; 
	cout << "Enter your name: "; 
	getline(cin, name); 
	//cin >> name; 
	//cin stops taking input at the first space char
	cout << "Your name is " << name << endl; 
	cout<< "Size: " << name.size() << endl; 
	cout << "name[1]: " << name[1] << endl;  
	cout << "name[1]: " << name.at(1) << endl;  
}

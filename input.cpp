#include<iostream>

using namespace std; 
int main(){
	int x,y; 
	cout<<"Enter an integer: "<<endl;
	if(cin >> x){
		cout<< "You enterend an integer" << x <<endl; 
	}else{
		cin.clear(); 
		cout << "Invalid input" <<endl; 
		return 0;
	}
	cout<<"Enter another integer" << endl; 
	cin >> y; 
	
	cout<<"The sum of the two integers :"<< x + y << endl; 

}

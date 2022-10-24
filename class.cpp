#include<iostream>
#include<string> 
using namespace std; 

class BankAccount{
	public: 
		//attributes
		int balance; 
		string name;

		//methods 
		void withdraw(int amt){
			balance = balance - amt; 
		}
		void print(){
			cout << name << " has " << balance << " rupees.";
		}
};
int main(){
	BankAccount account1; 
	account1.balance = 2000; 
	account1.name = "Akash"; 
	account1.print(); 
	account1.withdraw(100); 
	account1.print(); 


	return 0; 

}

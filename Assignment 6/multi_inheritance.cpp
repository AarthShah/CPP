//multiple level inheritance 
#include <iostream>
using namespace std;
class Parent1{
	public:
		int salary=50000;
};
class Parent2{
	public:
		int bonus=8000;
};

class Parent3{
	public:
		int food_allowance=2500;
};

class Child:public Parent1,public Parent2,public Parent3{
	public:
		int private_fund=2000;
		int insurance=2000;
	void exact_salary(){
		cout<<"The Total Salary is :"<<salary+bonus+food_allowance-private_fund-insurance<<endl;
	}
};
int main(){
	Child c1;
	c1.exact_salary();
}

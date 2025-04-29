//multiple level inheritance 
#include <iostream>
using namespace std;
class Parent{
	public:
		int salary=55000;
};
class Child1:public Parent{
	public:
		int bonus=8000;
};

class Child2:public Child1{
	public:
		int food_allowance=2500;
};

class Child3:public Child2{
	public:
		int private_fund=2000;
		int insurance=2000;
	void exact_salary(){
		cout<<"The Total Salary is :"<<salary+bonus+food_allowance-private_fund-insurance<<endl;
	}
};
int main(){
	Child3 c1;
	c1.exact_salary();
}

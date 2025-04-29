#include <iostream>
using namespace std;

void add(int a,int b){
	cout<<"The addition is :"<<a+b<<endl;
}

void add(double y,double z)
{
	cout<<"The addition is :"<<(y+z)<<endl;
}
int main(){
	add(33,66);
	add(33.33,66.66);
}


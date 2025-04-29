// Hybrid Inheritance
#include<iostream>
using namespace std;

class A {
public:
    int No_stu_a = 60;
};

class B {
public:
    int No_stu_b = 40;
};

class C : public A {
public:
    int No_stu_c = 50;
    void displayC() {
        cout << "Strength of class C: " << No_stu_c << endl;
    }
};

class D : public B, public C {
public:
    void display() {
        cout << "Strength of each class in Hybrid Inheritance:" << endl;
        cout << "A: " << No_stu_a << endl;
        cout << "B: " << No_stu_b << endl;
        cout << "C: " << No_stu_c << endl;
    }
};

int main() {
    D d;
    d.display();
    return 0;
}


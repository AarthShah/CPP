// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class ring{
    private:
        int radius;
        float area;
        string color;
    public:
        ring(){
            radius = 10;
            area = 3.14*(radius*radius);
            color = "red";
        }
        ring(int x){
            radius = x;
            area = 3.14*(radius*radius);
            color = "green";
        }
        void getRingInfo(){
            cout << "\nthe radius of Ring is :" << radius <<endl;
            cout << "the Area of Ring is : " << area <<endl;
            cout << " the color of ring is : " <<color << endl;
        }
        void setRingInfo(int rad){
            radius = rad;
            area = (float)3.14*(radius*radius);
            color = "yellow";
        }
        ~ring(){
            cout<<"\ndestructor is called"<<endl;
        }
};
int main() {
    ring r1;
    ring r2(6);
    r2.getRingInfo();
    r1.getRingInfo();
    r1.setRingInfo(5);
    r1.getRingInfo();
    
    return 0;
}

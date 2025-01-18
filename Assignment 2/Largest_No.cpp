#include<iostream>

using namespace std;

int main(){
    int a,b,c;
    cout<<"Enter Your First No :";
    cin>>a;
    cout<<endl<<"Enter Your Second  No :";
    cin>>b;
    cout<<endl<<"Enter Your Third No :";
    cin>>c;
    
    if(a>b && a>c){
        cout<<"The largest No is "<<a;
    }
    else if(b>a && b>c){
        cout<<"The largest No is "<<b;
    }
    else if(c>a && c>a){
        cout<<"The largest No is "<<c;
    }
    else{
        cout<<"It contain same elemets ";
    }
    return 0;
}
#include <iostream>

int main() {
    int ch , a,b;
    std::cout<<"Enter Your choice \n 1) Addition \n 2) Subtraction \n 3) Division \n 4) multiplication :-"<<std::endl;
    
    std::cin>> ch;
    
    if(ch<5){
            
        std::cout<<"Enter your first No for :- ";
        std::cin>>a;
        std::cout<<"Enter your second No for :- ";
        std::cin>>b;
        
        if(ch==1){
            
            std::cout<<"Addition of "<<a <<" & "<<b <<" is "<<a+b;
        }
        else if(ch==2){
            
             std::cout<<"Subtraction of "<<a <<" & "<<b <<" is "<<a-b;
        }
        else if(ch==3){
            
            std::cout<<"Division of "<<a <<" & "<<b <<" is "<<a/b;
        }
        else {
            
            std::cout<<"Multiplication of "<<a<<" & "<<b<<" is "<<a*b;
        }    
    }
    else{
        std::cout<<"Wrong input ";
    }
    return 0;
}
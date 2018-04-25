#include <iostream>
#include "CircularInt.cpp"
#include "CircularInt.hpp"

void test_add(){
    CircularInt a (2,12);
    a=a+3;//5
    if(a.current!=5){
        cout<<"problem 1 1"<<endl;
        cout<<a.current<<endl;
    }
    a=a+10;// 
    if(a.current!=4) {
        cout<<"problem 1 2"<<endl;
        cout<<a.current<<endl;
    }
    a=(-8)+a;
    if(a.current!=7){
        cout<<"problem 1 3"<<endl;
        cout<<a.current<<endl;

    }

    CircularInt b (-2,12);
    b=b+4; //2
    if(b.current!=2)
        cout<<"problem 2 1"<<endl;

    b=b+11;
    if(b.current!=-2){
        cout<<"problem 2 2"<<endl;
        cout<<b.current<<endl;
    }
    b=(-6)+b;
    if(b.current!=7){
        cout<<"problem 2 3"<<endl;
            cout<<b.current<<endl;
    }
    

    CircularInt c (-5,-1);
    c=c+1;
    if(c.current!=-4)
        cout<<"problem 3 1"<<endl;
    c=c+6;
    if(c.current!=-3)
        cout<<"problem 3 2"<<endl;
    c=(-10)+c;
        if(c.current!=-3){
        cout<<"problem 3 3"<<endl;
        cout<<c.current<<endl;
        }
}


int main(){
test_add();


return 0;
}



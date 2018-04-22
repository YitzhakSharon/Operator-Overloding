#include "CircularInt.hpp"
#include <iostream>
#include <cmath>

using namespace std;
CircularInt:: CircularInt(int a, int b){
        if(a<=b){
            this->begin=a;
            this->end=b;
        }else{
            this->begin=b;
            this->end=a;
        }
        this->current=begin;
    }
int range (CircularInt& other, int temp){
        
        if(temp>=other.begin && temp<=other.end)
            other.current=temp;
        else if(temp<other.begin){
            while(temp<other.begin){
                temp=temp+other.begin;
            }
            other.current=other.begin+temp+1;
        }
        else if(temp>other.end){
            while(temp>other.end){
                temp=temp-other.end;
            }
            other.current=other.end-temp+1;
        }
        return other.current;
           
       }

CircularInt operator+ (CircularInt& other, int num ){
        other.current =range(other,other.current+num);
        return other;

 }

CircularInt operator+ (int num, CircularInt& other ){
    other.current =range(other,other.current+num);
    return other;
}

CircularInt operator+ (CircularInt& a,CircularInt& b ){// what happend if they with change range
    a=a+b.current;
    return a;
}

CircularInt operator+= ( CircularInt& a, int num){
     a=a+num;
     return a;
 }

// CircularInt& CircularInt::operator++(){
//     (*this) += 1;
//     return *this;
// }
CircularInt operator++( CircularInt& other){
    other.current=other.current+1;
    return other;
}

CircularInt operator* ( CircularInt& other, int num){ 
    int temp = other.current*num;
    other.current = range(other,temp);
    return other;
}

CircularInt operator* ( int num, CircularInt& other){ 
    return other*num;
}

 CircularInt operator* ( CircularInt& a,CircularInt& b ){
    return b.current*a;
}

CircularInt operator*= (CircularInt& a, int num){
    a = a*num;
    return a;
}
// CircularInt& operator--(){
//     (this->current) =(*this->current)-1;
//     this->current=range(*this,*this->current);
// return this;
// }
// CircularInt operator--(const int other){
//     --(*this);
//     *this->current=range(*this,*this->current);
//     return copy;
// }
CircularInt operator/ ( CircularInt& other, int num ){
    if(num!=0)
        other.current=range(other,other.current/num);
    return other;

}
 CircularInt operator/= (  CircularInt& a, int num){
     return a/num;
 }
ostream& operator << (ostream& os, CircularInt const& ci) {
    os<<ci.current;
    return os;
}
istream& operator >> (istream& is,CircularInt& ci){
    is>>ci.current;
    ci.current=range(ci,ci.current);
    return is;
}
// int main(){

// CircularInt hour (1, 12);  
//  cin>>hour;
//  cout<<hour<<endl;               // <hour is an integer between 1 and 12, like an hour on the clock>
//  hour=hour+4;
//  hour=hour+3;
//  hour=hour/-2;
//  cout <<"divide:  "<< hour.current << endl;         // 5

//  hour=hour+18;
//    cout << hour << endl;         // 5
// return 0;
// }
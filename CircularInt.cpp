#include "CircularInt.hpp"
#include <iostream>
#include <cmath>

using namespace std;
    // CircularInt:: CircularInt(int a, int b):begin(a),end(b),current(a){
    //         if(a>b){
    //             this->begin=b;
    //             this->end=a;
    //             this->current=this->begin;

    //         }
    //     };

CircularInt::CircularInt(const CircularInt& a){
    this->begin=a.begin;
    this->end=a.end;
    this->current=a.current;
};

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

// CircularInt&operator++(){
//     (*this) += 1;
//     return *this;
// }
CircularInt& CircularInt::operator++()
{
    (*this) += 1;
    return *this;
}
CircularInt CircularInt::operator++(const int other){
    CircularInt aa (*this);
    ++(*this);
    return aa ;
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
    return a*b.current;
}

CircularInt operator*= (CircularInt& a, int num){
    a = a*num;
    return a;
}
CircularInt operator - (  int num,CircularInt& other ){
     other.current=range(other,num-other.current);
  return other;
}
CircularInt operator-(CircularInt& a){
    a.current=range(a,(-1)*a.current);
    return a;
}
CircularInt operator - (CircularInt& other, int num ){
    other.current=range(other,other.current-num);
    return other;

         }
CircularInt operator- ( CircularInt& a, CircularInt& b ){// we use twice at the same object - maybe we just return ziro
    a.current=range(a,a.current+b.current);
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
int main(){
	CircularInt hour {1, 12};                 // <hour is an integer between 1 and 12, like an hour on the clock>
	cout << hour << endl;                     // 1
	hour += 4;  
    cout << hour << endl;         // 5
	(hour += 2)++; 
     cout << hour << endl;     // 8
	hour += 18;   
    cout << hour << endl;       // 2   (18 hours after 8)
	cout << -hour << endl;                    // 10  (2 hours before midnight)
	hour = 1 - hour; 
    cout << hour << endl;    // 11  (2 hours before 1)
	cout << hour+hour << endl;                // 10 (11 hours after 11)
	hour *= 2;   
    cout << hour << endl;        // 10 (11*2 = 11+11)
	cout << hour/2 << endl;                   // TWO OPTIONS: 11 (since 11*2=10) or 5 (since 5*2=10 too).

	try {
		cout << hour/3;
	} catch (const string& message) {
		cout << message << endl;     // "There is no number x in {1,12} such that x*3=10"
	}

	// RIDDLES (not for submission): 
	//  * when is there exactly one answer to a/b?
//  * when are there two or more answers to a/b?
	//	* when is there no answer to a/b?
}
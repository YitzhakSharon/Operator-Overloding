#include "CircularInt.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

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
                temp=temp+(other.end-other.begin+1);
            }
            other.current=temp;

        }
        else if(temp>other.end){

            while(temp>other.end){
                temp=temp-(other.end-other.begin+1);
            }

            other.current=temp;
        }

        return other.current;
           
       }


std::ostream& operator << (std::ostream& os, CircularInt const& ci){
    os<<ci.current;
    return os;
}
istream& operator >> (istream& is,CircularInt& ci){
    is>>ci.current;
    ci.current=range(ci,ci.current);
    return is;
}
// <
bool operator <( CircularInt const& a ,  CircularInt const& b){return a.current<b.current;}
bool operator<(CircularInt const& a, int const& num){return a.current<num;}
bool operator<(int const& num,CircularInt const& a){return num<a.current;}


//> 
bool operator> (CircularInt const& a, CircularInt const& b){return a.current>b.current;}
bool operator> (CircularInt const& a, int const& num){ return a.current>num;}
bool operator> (int const& num, CircularInt const& a){return num>a.current;}

//==
bool operator== (CircularInt const& a, CircularInt const& b){return a.begin==b.begin && a.current==b.current && a.end==b.end;}
 bool operator== (CircularInt const& a, int const& num){return a.current==num;}
 bool operator== (int const& num, CircularInt const& a){return a.current==num;}

//!=
 bool operator!= (CircularInt const& a, CircularInt const& b){
      if(a.begin!=b.begin || a.current!=b.current || a.end!=b.end)
        return true;
    else return false;}
 bool operator!= (CircularInt const& a, int const& num){return a.current!=num;}
 bool operator!= (int const& num, CircularInt const& a){return a.current!=num;}

//<=
 bool operator<= (CircularInt const& a, CircularInt const& b){return a.current<=b.current;}
 bool operator<= (CircularInt const& a, int const& num){return a.current<=num;}
 bool operator<= (int const& num, CircularInt const& a){return num<=a.current;}

//=>

 bool operator>= (CircularInt const& a, CircularInt const& b){return a.current>=b.current;}
 bool operator>= (CircularInt const& a, int const& num){return a.current>=num;}
 bool operator>= (int const& num, CircularInt const& a){return num>=a.current;}

void CircularInt::operator=(int n){
    current = n;
    int numVal = this ->end - this->begin + 1;
    if(current > this->end){
        while(current > this->end)
            current -= numVal;
    }
    else if(current < this->begin){
        while(current < this->begin)
            current += numVal;    
    }    
}

void CircularInt::operator=(CircularInt cir){
    current = cir.current;
    int numVal = cir.end - cir.begin + 1;
    if(current > cir.end){
        while(current > cir.end)
            current -= numVal;
    }
    else if(current <cir.begin){
        while(current < cir.begin)
            current += numVal;    
    }    
}
// +	
CircularInt operator+  (CircularInt& c1,  CircularInt& c2){
    CircularInt a1 (c1);
    a1.current=range(a1,a1.current+c2.current);
    return a1;
}

CircularInt operator +  (CircularInt& c, int num){
    CircularInt a1 (c);
    a1.current =range(a1,a1.current+num);
    return a1;
}


CircularInt operator +  (int num, CircularInt c){
 CircularInt a1 (c);
    a1.current =range(a1,a1.current+num);
    return a1;
}

CircularInt& CircularInt::operator++()
{
    (*this) += 1;
    return *this;
}
CircularInt CircularInt::operator++( int other){
    CircularInt aa (*this);
    ++(*this);
    return aa ;
}

//+=

CircularInt& operator+=  (CircularInt& c1,  CircularInt& c2){

   CircularInt& a1 (c1);
    a1=c1+c2.current;
    cout<<a1<<endl;
    return a1;
 }

 CircularInt& operator+=  (CircularInt& c,  int num){
    CircularInt& a1 (c);
    a1.current=range(a1,a1.current+num);
    return a1;
}

//-
CircularInt& CircularInt::operator--(){
    (*this) -= 1;
    return *this;
}
CircularInt CircularInt::operator--( int other){
    CircularInt aa (*this);
    --(*this);
    return aa ;
}

CircularInt operator-(CircularInt& c1,  CircularInt& c2){
    CircularInt a1 (c1);
    a1.current=range(a1,a1.current-c2.current);
    return a1;
}
CircularInt operator-(CircularInt& c,  int num){
    CircularInt a1 (c);
    a1.current=range(a1,a1.current-num);
    return a1;
}
 CircularInt operator-  ( int num, CircularInt& c){
     CircularInt a1 (c);
    a1.current=range(a1,num-a1.current);
    return a1;
}

//-=

CircularInt& operator-=  (CircularInt& c1,  CircularInt& c2) {
  CircularInt& a1 (c1);
    a1.current=range(a1,a1.current-c2.current);
    return a1;
}

CircularInt& operator-=  (CircularInt& c, int  num){
	CircularInt& a1 (c);
    a1.current=range(a1,a1.current-num);
    return a1;
}

//*

 CircularInt operator*  (CircularInt& c1,  CircularInt& c2){
    CircularInt a1 (c1);
    a1.current=range(a1,a1.current*c2.current);
    return a1;
}
CircularInt operator*  (CircularInt& c,  int num){
    CircularInt &a1 (c);
    a1.current=range(a1,a1.current*num);
    return a1;
}

CircularInt operator*  ( int num, CircularInt c){
    CircularInt a1 (c);
    a1.current=range(a1,c.current*num);
    return a1;
}

// *=

 CircularInt& operator *=  (CircularInt& c1,  CircularInt& c2){
    CircularInt& a1 (c1);
    a1=a1*c2;
    cout<<a1<<"  a1"<<endl;
    return a1;
}
 CircularInt& operator *=  (CircularInt& c1,  int num){
    CircularInt& a1 (c1);
    a1=a1*num;
    cout<<a1<<"  a1"<<endl;
    return a1;
}



// /


CircularInt operator/ ( CircularInt& c1,  CircularInt& c2 ){
    CircularInt a1(c1);
    if(c2.current!=0 ){
        int i;
        for(i=c1.begin; i<c1.end; i++){
            if(i*c2==c1)
                a1.current=i;
        }
    }
        else{
                stringstream ss;
                ss << "There is no number x in {" << c1.begin << "," << c1.end << "} such that x*" << c2.current << "=" << c1.current;
                string s = ss.str();
                throw s;

     }
    return a1;
}

 CircularInt operator/ ( int  num, CircularInt& c){
    CircularInt a1(c);
    if(c.current!=0 ){
        int i;
        CircularInt a2(c);
        a2.current=num;
        for(i=c.begin; i<=c.end; i++){
            if(i*c==a2)
                a1.current=i;
        }
    }
        else{
                stringstream ss;
                ss << "There is no number x in {" << c.begin << "," << c.end << "} such that x*" << num << "=" << c.current;
                string s = ss.str();
                throw s;

     }
    return a1;
 }

CircularInt operator/ (CircularInt& c,  int  num){
    CircularInt a1(c);
    if(c.current!=0 ){
        int i;
        CircularInt a2(c);
        a2.current=num;

        for(i=c.begin; i<=c.end; i++){
            if(i*a2==c)
                a1.current=i;
        }
    }
        else{
                stringstream ss;
                ss << "There is no number x in {" << c.begin << "," << c.end << "} such that x*" << num << "=" << c.current;
                string s = ss.str();
                throw s;

     }
    return a1;
}

// =/
 CircularInt& operator/= (CircularInt& c1,  CircularInt& c2){
	 CircularInt& a1(c1);
     a1=c1/c2;
     return a1;
}
CircularInt& operator/= (CircularInt& c,  int  num)  {
        CircularInt& a1 (c);
        a1=c/num;
    return a1;
}    
// int main(){


//     CircularInt a (1,10);
//     CircularInt b(2,10);
//     a.current=4;
//     b.current=2;
//     a=a/0;
//     cout<<a<<"  2"<<endl;
//     a.current=4;
//     a/=2;
//     cout<<a<<"  2"<<endl;
//     a.current=2;
//     a=4/a;
//     cout<<a<<"  2"<<endl;


// return 0;
// }

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
bool operator <( CircularInt const& a ,  CircularInt const& b){return a.current>b.current;}
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
 bool operator!= (CircularInt const& a, CircularInt const& b){return a.begin!=b.begin && a.current!=b.current && a.end!=b.end;}
 bool operator!= (CircularInt const& a, int const& num){return a.current!=num;}
 bool operator!= (int const& num, CircularInt const& a){return a.current!=num;}

//<=
 bool operator<= (CircularInt const& a, CircularInt const& b){return a.current<=b.current;}
 bool operator<= (CircularInt const& a, int const& num){return a.current<=num;}
 bool operator<= (int const& num, CircularInt const& a){return num<a.current;}

//=>

 bool operator>= (CircularInt const& a, CircularInt const& b){return a.current>=b.current;}
 bool operator>= (CircularInt const& a, int const& num){return a.current>=num;}
 bool operator>= (int const& num, CircularInt const& a){return num>=a.current;}

  CircularInt CircularInt::operator=(const int num)
{
    this->current = num;
    (*this) += 0;
    return *this;
}
CircularInt CircularInt::operator=(const CircularInt& c){
    CircularInt a (c);
    a.current=c.current;
    return a; 
}

// +	
CircularInt operator+  (CircularInt c1, CircularInt const& c2){
    CircularInt a1 (c1);
    a1.current=range(a1,a1.current+c2.current);
    return a1;
}

CircularInt operator+  (CircularInt c, int const& num){
    CircularInt a1 (c);
    a1.current =range(a1,a1.current+num);
    return a1;
}


CircularInt operator+  ( int const& num,  CircularInt a){
 CircularInt a1 (a);
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

CircularInt operator+=  (CircularInt& c1, CircularInt const& c2){

   CircularInt a1 (c1);
    a1.current=range(a1,a1.current+c2.current);
    return a1;
 }

 CircularInt operator+=  (CircularInt& c, int const& num){
    CircularInt a1 (c);
    a1.current=range(a1,a1.current+num);
    return a1;
}

//-

CircularInt operator-(CircularInt c1, CircularInt const& c2){
    CircularInt a1 (c1);
    a1.current=range(a1,a1.current-c2.current);
    return a1;
}
CircularInt operator-(CircularInt c, int const& num){
    CircularInt a1 (c);
    a1.current=range(a1,a1.current-num);
    return a1;
}
CircularInt operator-  (int const& num, CircularInt c){
     CircularInt a1 (c);
    a1.current=range(a1,num-a1.current);
    return a1;
}

//-=

CircularInt operator-=  (CircularInt& c1, CircularInt const& c2) {
  CircularInt a1 (c1);
    a1.current=range(a1,a1.current-c2.current);
    return a1;
}

CircularInt operator-=  (CircularInt& c, int const& num){
	CircularInt a1 (c);
    a1.current=range(a1,a1.current-num);
    return a1;
}

//*

 CircularInt operator*  (CircularInt c1, CircularInt const& c2){
    CircularInt a1 (c1);
    a1.current=range(a1,a1.current*c2.current);
    return a1;
}
CircularInt operator*  (CircularInt c, int const& num){
    CircularInt &a1 (c);
    a1.current=range(a1,a1.current*num);
    return a1;
}

CircularInt operator*  (int const& num, CircularInt c){
    CircularInt a1 (c);
    a1.current=range(a1,a1.current*num);
    return a1;
}

// *=

 CircularInt operator*=  (CircularInt& c1, CircularInt const& c2){
    CircularInt a1 (c1);
    a1.current=range(a1,a1.current*c2.current);
    return a1;
}

CircularInt operator*=  (CircularInt& c, int const& num) {
    CircularInt a1 (c);
    a1.current=range(a1,a1.current*num);
    return a1;
}


// /

CircularInt operator/= (CircularInt& c, int const& num)  {
        CircularInt a1 (c);
     if(c.current % num == 0 && num!=0){
        a1.current =range(a1,a1.current/num);
        return a1;

    }
    else {
        stringstream ss;
        ss << "There is no number x in {" << c.begin << "," << c.end << "} such that x*" << num << "=" << c.current;
        string s = ss.str();
        throw s;
    }
    return a1;
}    

CircularInt operator/ ( CircularInt& c1, CircularInt const& c2 ){
    CircularInt a1(c1);
    if(c2.current!=0){
        a1.current=range(a1,a1.current/c2.current);
        return a1;
    }
    return a1;
}

 CircularInt operator/ (int const& num, CircularInt c){
     CircularInt a1 (c);
    if(num % c.current == 0 && c.current!=0){
        a1.current =range(a1,num/a1.current);
        return a1;

    }
    else {
        stringstream ss;
        ss << "There is no number x in {" << c.begin << "," << c.end << "} such that x*" << num << "=" << c.current;
        string s = ss.str();
        throw s;
    }
    return a1;


    }

CircularInt operator/ (CircularInt c, int const& num){
	if(c.current!=0 && num%c.current==0){
		CircularInt a1(c);
		 a1.current=range(a1,num/a1.current);
		return a1;
		}
	else{
		return c;
		}
}

// =/
 CircularInt operator/= (CircularInt& c1, CircularInt const& c2){
	CircularInt a1(c1);
	if(a1.current%c2.current==0 &&c2.current!=0){
        a1.current=range(a1,a1.current/c2.current);

    }
    else{
        stringstream ss;
        ss << "There is no number x in {" << c1.begin << "," << c1.end << "} such that x*" <<  c2.current<< "=" << c1.current;
        string s = ss.str();
        throw s;
 
    }
    return a1;
}


// CircularInt& CircularInt::operator/=(const int num){
//     if(current % num == 0){
//         current /= num;
//         (*this) += 0;
//     }
//     else {
//         stringstream ss;
//         ss << "There is no number x in {" << begin << "," << end << "} such that x*" << num << "=" << current;
//         string s = ss.str();
//         throw s;
//     }
//     return *this;
// }  

// %

const CircularInt operator % ( CircularInt& a ,  CircularInt& b){
    CircularInt a1 (a);
    a1.current=range(a1,a1.current%b.current);
    return a1;
}

CircularInt operator% ( CircularInt & a ,  int & num){
    CircularInt a1 (a);
    a1.current=range(a1,a1.current%num);
    return a1;
}
CircularInt operator%  (int  num, CircularInt& a){
	  CircularInt a1 (a);
    	a1.current=range(a1,num&a1.current);
	return a1;
}

//%=

CircularInt operator%=  (CircularInt& a, CircularInt& b){

    CircularInt a1 (a);
    a1.current=range(a1,a1.current%b.current);
    return a1;
}
 CircularInt operator%=  (CircularInt& a, int num){

    CircularInt a1 (a);
    a1.current=range(a1,a1.current%num);
    return a1;
}












       

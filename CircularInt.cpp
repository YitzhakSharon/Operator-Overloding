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
std::ostream& operator << (std::ostream& os, CircularInt const& ci){
    os<<ci.current;
    return os;
}
istream& operator >> (istream& is,CircularInt& ci){
    is>>ci.current;
    ci.current=range(ci,ci.current);
    return is;
}

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



// <
bool operator <(const CircularInt const& a ,  CircularInt const& b){return a.current>b.current;}
bool operator<(CircularInt const& a, int const& num){return a.current<num;}
bool operator<(int const& num,CircularInt const& a){return num<a.current;}


//> 
bool operator> (CircularInt const& a, CircularInt const& b){return a.current>b.current;}
bool operator> (CircularInt const& a, int const& num){ return a.current>num;}
friend bool operator> (int const& num, CircularInt const& a){num>a.current;}

//==
bool operator== (CircularInt const& a, CircularInt const& b){return a.begin==b.begin && a.current==b.current && a.end==b.end;}
friend bool operator== (CircularInt const& a, int const& num){return a.current==num;}
friend bool operator== (int const& num, CircularInt const& a){return a.current==num;}

//!=
friend bool operator!= (CircularInt const& a, CircularInt const& b){return a.begin!=b.begin && a.current!=b.current && a.end!=b.end;}
friend bool operator!= (CircularInt const& a, int const& num){return a.current!=num;}
friend bool operator!= (int const& num, CircularInt const& a){return a.current!=num;}

//<=
 bool operator<= (CircularInt const& a, CircularInt const& b){return a.current<=b.current;}
 bool operator<= (CircularInt const& a, int const& num){return a.current<=num;}
 bool operator<= (int const& num, CircularInt const& a){return num<a.current;}

//=>

 bool operator>= (CircularInt const& a, CircularInt const& b){return a.current>=b.current;}
 bool operator>= (CircularInt const& a, int const& num){return a.current>=num;}
 bool operator>= (int const& num, CircularInt const& a){return num=>a.current}

// +	
CircularInt& operator+  (CircularInt const& a, CircularInt const& b){
    CircularInt &a1 (a);
    a1.current=range(a1,a1.current+b.current);
    return a1;
}

CircularInt& operator+  (CircularInt  cosnt& a, int const& num){
    CircularInt &a1 (a);
    a1.current =range(a1,a1.current+num);
    return a1;
}


CircularInt& operator+  (int const& num, CircularInt a){
 CircularInt &a1 (a);
    a1.current =range(a1,a1.current+num);
    return a1;
}
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

//+=

CircularInt& operator+=  (CircularInt const& a, CircularInt const& b){
    CircularInt &a1 (a);
    a1.current=range(a1,a1.current+b.current);
    return a1;
 }

CircularInt& operator+=  (CircularInt cosnt& a, int const& num){
    CircularInt &a1 (a);
    a1.current=range(a1,a1.current+num);
    return a1;
 
}

//-

CircularInt& operator-  (CircularInt const& a, CircularInt const& b){
    CircularInt &a1 (a);
    a1.current=range(a1,a1.current-b.current);
    return a1;
}
CircularInt& operator-  (CircularInt const& a, int const& num){
    CircularInt &a1 (a);
    a1.current=range(a1,a1.current-num);
    return a1;
}
CircularInt& operator-  (int const& num, CircularInt const& a){
     CircularInt &a1 (a);
    a1.current=range(a1,num-a1.current);
    return a1;
}

//-=

CircularInt operator-=  (CircularInt const& a, CircularInt const& b){
    CircularInt &a1 (a);
    a1.current=range(a1,a1.current-b.current);
    return a1;
}

CircularInt operator-=  (CircularInt cosnt& a, int const& num){
	CircularInt &a1 (a);
    a1.current=range(a1,a1.current-num);
    return a1;
}

//*

 CircularInt& operator*  (CircularInt const& a, CircularInt const& b){
    CircularInt &a1 (a);
    a1.current=range(a1,a1.current*b.current);
    return a1;
}
CircularInt& operator*  (CircularInt const& a, int const& num){
    CircularInt &a1 (a);
    a1.current=range(a1,a1.current*num);
    return a1;
}
CircularInt& operator*  (int const& num, CircularInt const& a){
    CircularInt &a1 (a);
    a1.current=range(a1,a1.current*num);
    return a1;
}

// *=

 CircularInt& operator*=  (CircularInt const& a, CircularInt const& b){
    CircularInt &a1 (a);
    a1.current=range(a1,a1.current*b.current);
    return a1;
}
 CircularInt& operator*=  (CircularInt const& a, int const& num){ 
    CircularInt &a1 (a);
    a1.current=range(a1,a1.current*num);
    return a1;
}

// /
CircularInt operator/ ( CircularInt const& a, int const& num ){
    CircularInt other1 (other);
    other/=num;
    return other;

}

CircularInt& CircularInt::operator/=(const int num){
    if(current % num == 0){
        current /= num;
        (*this) += 0;
    }
    else {
        stringstream ss;
        ss << "There is no number x in {" << begin << "," << end << "} such that x*" << num << "=" << current;
        string s = ss.str();
        throw s;
    }
    return *this;
}    
CircularInt operator/ ( CircularInt const& a, CircularInt const& b ){
    CircularInt a1(a);
    if(b.current!=0){
        a1.current=range(a1,a1.current/b.current);
        return other;
    }
    return other;
}

CircularInt operator/  (int const& num, CircularInt const& a){
	if(a.current!=0 && num%a.current==0){
		CircularInt a1(a);
		 a1.current=range(a1,num/a.current);
		return a1;
		}
	else{
		return a;
		}
}

// =/
 CircularInt operator/=  (CircularInt cosnt& a, CircularInt const& b){
	CircularInt a1(a);
	a1=a/b;
	return a1;
}


CircularInt& CircularInt::operator/=(const int num){
    if(current % num == 0){
        current /= num;
        (*this) += 0;
    }
    else {
        stringstream ss;
        ss << "There is no number x in {" << begin << "," << end << "} such that x*" << num << "=" << current;
        string s = ss.str();
        throw s;
    }
    return *this;
}  

// %

const CircularInt operator % (const CircularInt& a , const CircularInt& b){
    CircularInt a1 (a);
    a1.current=range(a1,a1.current%b.current);
    return a1;
}

CircularInt operator% ( CircularInt const& a ,  int const& num){
    CircularInt a1 (a);
    a1.current=range(a1,a1.current%num);
    return a1;
}
CircularInt operator%  (int const& num, CircularInt const& a){
	  CircularInt a1 (a);
    	a1.current=range(a1,num&a1.current);
	returb a1;
}

//%=

CircularInt operator%=  (CircularInt const& a, CircularInt const& b){

    CircularInt a1 (a);
    a1.current=range(a1,a1.current%b.current);
    return a1;
}
 CircularInt operator%=  (CircularInt& a, int const& num);

    CircularInt a1 (a);
    a1.current=range(a1,a1.current%num);
    return a1;
}












       

// CircularInt& operator+ (CircularInt& other, int num ){
//     CircularInt &other1 (other);
//     other1.current =range(other1,other1.current+num);
//     return other1;

//  }

// CircularInt& operator+ (int num, CircularInt& other ){
//     CircularInt &other1 (other);
//     other1.current =range(other1,other1.current+num);
//     return other1;
// }

// CircularInt& operator+ (CircularInt& a,CircularInt& b ){// what happend if they with change range
//     CircularInt &a1 (a);
//     a1.current=range(a1,a1.current+b.current);
//     return a1;
// }

// CircularInt& operator+= ( CircularInt& a, int num){
//     CircularInt &a1 (a);
//     a1.current=range(a1,a1.current+num);
//      return a1;
//  }

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
// CircularInt& operator* (  CircularInt& other, int num){ 
//     CircularInt &other1 (other);
//     int temp = other1.current*num;
//     other1.current = range(other1,temp);
//     return other1;
// }

// CircularInt& operator* ( int num, CircularInt& other){ 
//     CircularInt &other1 (other);
//     other1.current=range(other1,other1.current*num);
//     return other1;
// }

//  CircularInt& operator* ( CircularInt& a,CircularInt& b ){
//     CircularInt &a1 (a);
//     a1.current=range(a1,a1.current*b.current);
//     return a1;
// }

// CircularInt& operator*= (CircularInt& a, int num){
//     CircularInt &a1 (a);
//     a1.current=range(a1,a1.current*num);
//     return a1;
// }
// CircularInt& operator - (  int num,CircularInt& other ){
//     CircularInt &other1 (other);
//      other1.current=range(other1,num-other1.current);
//   return other1;
// }
// CircularInt CircularInt::operator-(){
//     CircularInt a1 (*this);
//     a1*=-1;
//     return a1;
// }
// CircularInt& operator - (CircularInt& other, int num ){
//     CircularInt &other1 (other);
//     other1.current=range(other1,other1.current-num);
//     return other1;

//          }
// CircularInt& operator- ( CircularInt& a, CircularInt& b ){// we use twice at the same object - maybe we just return ziro
//     CircularInt &a1 (a);
//     a1.current=range(a1,a1.current+b.current);
//     return a1;
// }

// CircularInt operator/ ( CircularInt& other, int num ){
//     CircularInt other1 (other);
//     other/=num;
//     return other;

// }

// CircularInt& CircularInt::operator/=(const int num)
// {
//     if(current % num == 0)
//     {
//         current /= num;
//         (*this) += 0;
//     }
//     else 
//     {
//         stringstream ss;
//         ss << "There is no number x in {" << begin << "," << end << "} such that x*" << num << "=" << current;
//         string s = ss.str();
//         throw s;
//     }
//     return *this;
// }    
// CircularInt operator/ ( CircularInt& a, CircularInt& b ){
//     CircularInt other(a);
//     if(b.current!=0){
//         other.current=range(a,a.current/b.current);
//         return other;
//     }
//     return other;
// }

// bool operator==(const CircularInt a , const CircularInt b){
//     return a.begin==b.begin && a.current==b.current && a.end==b.end;
// }
// bool operator!=(const CircularInt a , const CircularInt b){
//     return a.begin!=b.begin && a.current!=b.current && a.end!=b.end;
// }
// bool operator >(const CircularInt a , const CircularInt b){
//     return a.current>b.current;
// }
// bool operator <(const CircularInt a , const CircularInt b){
//     return  a.current<b.current;
// }
// bool operator>=(const CircularInt a , const CircularInt b){
//     return a.current>=b.current;
// }
// bool operator<=(const CircularInt a , const CircularInt b){
//     return  a.current<=b.current;
// }
// const CircularInt operator% (const CircularInt& a , const int num){
//     CircularInt a1 (a);
//     a1.current=range(a1,a1.current%num);
//     return a1;
// }
// const CircularInt operator % (const CircularInt& a , const CircularInt& b){
//     CircularInt a1 (a);
//     a1.current=range(a1,a1.current%b.current);
//     return a1;
// }

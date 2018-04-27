#include<iostream>
#pragma once
using namespace std;

class CircularInt{
    public:
        int begin;
        int end;
        int current;
    //
    friend istream& operator >> (istream& is,CircularInt& ci);
    friend ostream& operator << (std::ostream& os, CircularInt const& ci);
    friend CircularInt operator~ (CircularInt const c);
    friend CircularInt operator- (CircularInt const c);
    // CircularInt operator-();


    // 
    friend bool operator<(CircularInt const& a, CircularInt const& b);
    friend bool operator<(CircularInt const& a, int const& num);
    friend bool operator<(int const& num,CircularInt const& a);
                
    friend bool operator> (CircularInt const& a, CircularInt const& b);
    friend bool operator> (CircularInt const& a, int const& num);
    friend bool operator> (int const& num, CircularInt const& a);

    friend bool operator== (CircularInt const& a, CircularInt const& b);
    friend bool operator== (CircularInt const& a, int const& num);
    friend bool operator== (int const& num, CircularInt const& a);

    friend bool operator!= (CircularInt const& a, CircularInt const& b);
    friend bool operator!= (CircularInt const& a, int const& num);
    friend bool operator!= (int const& num, CircularInt const& a);

    friend bool operator<= (CircularInt const& a, CircularInt const& b);
    friend bool operator<= (CircularInt const& a, int const& num);
    friend bool operator<= (int const& num, CircularInt const& a);

    friend bool operator>= (CircularInt const& a, CircularInt const& b);
    friend bool operator>= (CircularInt const& a, int const& num);
    friend bool operator>= (int const& num, CircularInt const& a);

    // Algebra
	friend CircularInt operator +  (CircularInt& c1, CircularInt& c2);
	friend CircularInt operator +  (CircularInt& c, int num);
	friend CircularInt operator +  (int num, CircularInt c);

	friend CircularInt operator-  (CircularInt& c1,  CircularInt& c2);
	friend CircularInt operator-  (CircularInt& c,  int  num);
	friend CircularInt operator-  ( int num, CircularInt& c);

	friend CircularInt operator*  (CircularInt& c1,  CircularInt& c2);	
	friend CircularInt operator*  (CircularInt& c,  int  num);	
	friend CircularInt operator*  (int num, CircularInt c);

    friend CircularInt operator/ (CircularInt& c1,  CircularInt c2);
    friend CircularInt operator/ (CircularInt& c,  int num); 
    friend CircularInt operator/ ( int num, CircularInt c);


    friend CircularInt& operator+=  (CircularInt& c1,  CircularInt& c2);
    friend CircularInt& operator+=  (CircularInt& c,  int  num);	

	friend CircularInt& operator-=  (CircularInt& c1,  CircularInt& c2);
    friend CircularInt& operator-=  (CircularInt& c,  int  num);	
    CircularInt&  operator *= ( int num);
    friend  CircularInt& operator*=  (CircularInt& c, int num);
    friend CircularInt& operator*=  (CircularInt& c1,  CircularInt& c2);

    friend CircularInt& operator/= (CircularInt& c1,  CircularInt& c2);
    friend CircularInt& operator/= (CircularInt& c,  int  num); 



public:
    CircularInt(int a, int b):begin(a),end(b),current(a){
            if(a>b){
                this->begin=b;
                this->end=a;
                this->current=this->begin;
            }
        };
       // CircularInt(int a, int b);
    CircularInt range (CircularInt& other, int temp);
    CircularInt (const CircularInt& a);
            CircularInt operator++(const int other)  ;
            CircularInt& operator ++ ();// prefix
            CircularInt& operator -- ();
             CircularInt operator--(const int other)  ;
    void operator=( CircularInt c);
    void operator=( int num);


};
    //     friend istream& operator>> (istream& is,CircularInt& ci);
    //     friend ostream& operator<< (std::ostream& os, CircularInt const& ci);
    //     friend CircularInt& operator+ ( CircularInt& other, int num );
    //     friend CircularInt& operator+ ( int num, CircularInt& other );
    //     friend CircularInt& operator + (CircularInt& a, CircularInt& b);// we use twice at the same object
    //     friend CircularInt& operator - (  int num,CircularInt& other );
    //     friend CircularInt& operator - (CircularInt& other, int num );
    //     friend CircularInt& operator- ( CircularInt& a, CircularInt& b );// we use twice at the same object - maybe we just return ziro
    //      friend CircularInt operator- (CircularInt const c);
    //     friend CircularInt& operator+= (  CircularInt& a, int num);
    //     friend CircularInt& operator-= (  CircularInt& a, int num);
    // //    friend CircularInt operator^ (  CircularInt& a, int num);
    // //    friend CircularInt operator^= (  CircularInt& a, int num);
    //   friend CircularInt operator/ ( CircularInt& other, int num );  // cheak divid ziro  (num!=0)
    // friend CircularInt operator/ ( CircularInt& a, CircularInt& b );  // cheak divid ziro  - current =!0 return 1

    //     friend CircularInt& operator* ( CircularInt& other, int num);
    //     friend CircularInt& operator* ( CircularInt& a,CircularInt& b );//we use twice at the same object
    //     friend CircularInt& operator* ( int num, CircularInt& other);
    //     friend CircularInt& operator*= (  CircularInt& a, int num);
    //     CircularInt& operator/= ( const int num);
    //     friend bool operator==(const CircularInt a , const CircularInt b);
    //     friend bool operator!=(const CircularInt a , const CircularInt b); 
    //     friend bool operator>(const CircularInt a , const CircularInt b); 
    //     friend bool operator<(const CircularInt a , const CircularInt b);  
    //     friend bool operator>=(const CircularInt a , const CircularInt b); 
    //     friend bool operator<=(const CircularInt a , const CircularInt b);
    //     friend const CircularInt operator% (const CircularInt& a , const int num);
    //     friend const  CircularInt operator%=(const CircularInt a , const CircularInt b);




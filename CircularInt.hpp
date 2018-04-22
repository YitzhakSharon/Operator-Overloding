#include<iostream>
#pragma once
using namespace std;

class CircularInt{
    public:
        int begin;
        int end;
        int current;
    public:
        friend istream& operator>> (istream& is,CircularInt& ci);
        friend ostream& operator<< (std::ostream& os, CircularInt const& ci);
        friend CircularInt& operator+ ( CircularInt& other, int num );
        friend CircularInt& operator+ ( int num, CircularInt& other );
        friend CircularInt& operator + (CircularInt& a, CircularInt& b);// we use twice at the same object
        friend CircularInt& operator - (  int num,CircularInt& other );
        friend CircularInt& operator - (CircularInt& other, int num );
        friend CircularInt& operator- ( CircularInt& a, CircularInt& b );// we use twice at the same object - maybe we just return ziro
         CircularInt operator-();
        friend CircularInt& operator+= (  CircularInt& a, int num);
        friend CircularInt& operator-= (  CircularInt& a, int num);
        // friend CircularInt& operator ++ ();// prefix

    //    friend CircularInt operator%= (  CircularInt& a, int num);
    //    friend CircularInt operator^ (  CircularInt& a, int num);
    //    friend CircularInt operator^= (  CircularInt& a, int num);
      // friend CircularInt operator/ ( CircularInt& other, int num );  // cheak divid ziro  (num!=0)
    //    friend CircularInt operator/ (int num,CircularInt& other );  // cheak divid ziro  (num!=0)
    //    friend CircularInt operator/ ( CircularInt& a, CircularInt& b );  // cheak divid ziro  - current =!0 return 1

//hadar:
 //    friend CircularInt operator> ( const CircularInt& a, cosnt CircularInt& b);
    //    friend CircularInt operator< ( const CircularInt& a, cosnt CircularInt& b);
    //    friend CircularInt operator<= ( const CircularInt& a, cosnt CircularInt& b);
    //    friend CircularInt operator>= ( const CircularInt& a, cosnt CircularInt& b);
        friend CircularInt& operator* ( CircularInt& other, int num);
        friend CircularInt& operator* ( CircularInt& a,CircularInt& b );//we use twice at the same object
        friend CircularInt& operator* ( int num, CircularInt& other);
        friend CircularInt& operator*= (  CircularInt& a, int num);
        CircularInt& operator/= ( const int num);
    //    friend CircularInt operator% ();
    //    friend CircularInt operator== ( const CircularInt& a, cosnt CircularInt& b);
    //    friend CircularInt operator!= ( const CircularInt& a, cosnt CircularInt& b);
         CircularInt operator++(const int other)  ;
        CircularInt& operator ++ ();// prefix



   
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


};


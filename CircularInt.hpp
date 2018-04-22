#include<iostream>
#pragma once
using namespace std;

class CircularInt{
    public:
        int begin;
        int end;
        int current;

        friend istream& operator>> (istream& is,CircularInt& ci);
        friend ostream& operator<< (ostream& os, CircularInt const& ci);
        friend CircularInt operator+ ( CircularInt& other, int num );
        friend CircularInt operator+ ( int num, CircularInt& other );
        friend CircularInt operator + (CircularInt& a, CircularInt& b);// we use twice at the same object
        friend CircularInt operator - (  int num,CircularInt& other );
        friend CircularInt operator - (CircularInt& other, int num );
        friend CircularInt operator- ( CircularInt& a, CircularInt& b );// we use twice at the same object - maybe we just return ziro
        friend CircularInt operator+= (  CircularInt& a, int num);
        friend CircularInt operator-= (  CircularInt& a, int num);
         friend  CircularInt operator ++ ( CircularInt& other);//postfix
        // friend CircularInt& operator ++ ();// prefix

        friend CircularInt operator/= (  CircularInt& a, int num);
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
        friend CircularInt operator* ( CircularInt& other, int num);
        friend CircularInt operator* ( CircularInt& a,CircularInt& b );//we use twice at the same object
        friend CircularInt operator* ( int num, CircularInt& other);
        friend CircularInt operator*= (  CircularInt& a, int num);
    //    friend CircularInt operator% ();
    //    friend CircularInt operator== ( const CircularInt& a, cosnt CircularInt& b);
    //    friend CircularInt operator!= ( const CircularInt& a, cosnt CircularInt& b);
        // friend CircularInt operator-- (const int other);
        // friend CircularInt& operator -- ();// prefix



   
    public:
        CircularInt(int a, int b);
        CircularInt range (CircularInt& other, int temp);


};


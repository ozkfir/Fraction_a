#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
namespace ariel{}
#ifndef GAME_H
#define GAME_H


class  Fraction {
    int numerator;
    int denominator;
private:

    void negtive();

    void reduced();
public:
    Fraction(int a,int b);
    Fraction(float b);


    friend Fraction& operator++(Fraction &a);
    friend const Fraction operator++(Fraction &b,int a);
    friend Fraction& operator--(Fraction& a);
    friend const Fraction operator--(Fraction &b,int a);



    friend Fraction operator+(const Fraction & a,const Fraction & b);
    friend Fraction operator*(const Fraction & a,const Fraction  & b);
    friend Fraction operator-(const Fraction & a,const Fraction & b);
    friend Fraction operator/(const Fraction & a,const Fraction & b);


    friend istream &operator>>(istream  &input,Fraction &b);
    friend ostream &operator<<(ostream &output,const Fraction &b);


    friend bool operator<(const Fraction & a,const  Fraction  & b);
    friend bool operator<=(const Fraction & a,const Fraction & b);
    friend bool operator>(const Fraction & a,const Fraction & b);
    friend bool operator>=(const Fraction & a,const Fraction & b);
    friend bool operator==(const Fraction & a,const Fraction & b);

    };
#endif

//    bool operator<(float b);
//    bool operator<=(float b);
//    bool operator>(float b);
//    bool operator>=(float b);
//    bool operator==(float b);

//    Fraction operator+(float b);
//    Fraction operator*(float b);
//    Fraction operator-(float b);
//    Fraction operator/(float b);


//    friend Fraction operator+(float a,Fraction b);
//    friend Fraction operator*(Fraction a,Fraction b);



//    friend Fraction operator-(float a,Fraction b);
//    friend Fraction operator/(float a,Fraction b);
//    friend  bool operator<(float a,Fraction b);
//    friend bool operator<=(float a,Fraction b);
//    friend bool operator>(float a,Fraction b);
//    friend bool operator>=(float a,Fraction b);
//    friend bool operator==(float a,Fraction b);
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
    Fraction();

    int getNumerator();
    int getDenominator();

    friend Fraction& operator++(Fraction &a);
    friend const Fraction operator++(Fraction &b,int a);

    friend Fraction& operator--(Fraction& a);
    friend const Fraction operator--(Fraction &b,int a);



    friend const Fraction operator+(const Fraction & a,const Fraction & b);
    friend const Fraction operator*(const Fraction & a,const Fraction  & b);
    friend const Fraction operator-(const Fraction & a,const Fraction & b);
    friend const Fraction operator/(const Fraction & a,const Fraction & b);


    friend istream &operator>>(istream  &input,Fraction &b);
    friend ostream &operator<<(ostream &output,const Fraction &b);


    friend const bool operator<(const Fraction & a,const  Fraction  & b);
    friend const bool operator<=(const Fraction & a,const Fraction & b);
    friend const bool operator>(const Fraction & a,const Fraction & b);
    friend const bool operator>=(const Fraction & a,const Fraction & b);
    friend const bool operator==(const Fraction & a,const Fraction & b);

    };
#endif

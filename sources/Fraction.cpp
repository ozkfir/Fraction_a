#include <iostream>
#include "Fraction.hpp"
using namespace std;



using std::cout; using std::endl;

void Fraction::negtive(){
    if (this->denominator<0)
    {
        this->numerator*=-1;
        this->denominator*=-1;
    }
}

int Fraction::getNumerator(){
    return this->numerator;
}
int Fraction::getDenominator(){
    return this->denominator;
}
int Gcd(int a, int b)
{
    if (b == 0)
        return ((0 < a) ? a : -a);
    return Gcd(b, a % b);
}




void Fraction::reduced() {
    int i=Gcd(this->numerator,this->denominator);
    this->numerator/=i;
    this->denominator/=i;
    this->negtive();
}


Fraction::Fraction(float b)
{
    int gcd= Gcd((int)(b*1000),1000);
   this->numerator=((int)(b*1000))/gcd;
    this->denominator=1000/gcd;
}

Fraction::Fraction()
{
    this->numerator=1;
    this->denominator=1;
}

Fraction::Fraction(int a,int b){
    if(b==0){ throw runtime_error("Math error: Attempted to divide by Zero\n");}
    this->numerator=a;
    this->denominator=b;
    this->reduced();
}


Fraction const operator+(const Fraction & a,const Fraction & b){
    int numerator=a.numerator*b.denominator+ a.denominator* b.numerator;
    int denominator=a.denominator*b.denominator;
    Fraction t(numerator,denominator);
    return t;
}

Fraction const operator*(const Fraction & a,const Fraction & b){
    Fraction t(a.numerator*b.numerator, a.denominator*b.denominator);
    return t;
}

Fraction const operator-(const Fraction & a,const Fraction & b){
    int numerator=a.numerator*b.denominator-a.denominator* b.numerator;
    int denominator=a.denominator*b.denominator;
    Fraction t(numerator,denominator);
    return t;
}

Fraction const operator/(const Fraction & a,const Fraction & b){
    if(b.numerator==0){ throw runtime_error("Math error: Attempted to divide by Zero\n");}
    Fraction t(a.numerator*b.denominator,a.denominator*b.numerator);
    return t;
}


const Fraction operator++(Fraction& b,int a){
    Fraction t(b.numerator,b.denominator);
    b.numerator+=b.denominator;
    return t;
}

Fraction& operator++(Fraction &b){
    b.numerator+=b.denominator;
    return b;
}

Fraction& operator--(Fraction &b){
    b.numerator-=b.denominator;
    return b;
}

const Fraction operator--(Fraction &b,int a){
    Fraction t(b.numerator,b.denominator);
    b.numerator-=b.denominator;
    return t;
}

istream& operator>>(istream  &cin,Fraction &b){
    if((cin.gcount()%2)==1){throw  std::invalid_argument("runtime");}
    char c;
    cin >> b.numerator >> b.denominator;
    if(b.denominator==0){ throw runtime_error("Math error: Attempted to divide by Zero\n");}
    b.reduced();
    return cin;
}


ostream& operator<<(ostream &output,const Fraction &b) {
    output << ""<<b.numerator << "/" << b.denominator<<"";
    return output;
}

const bool operator==(const Fraction & a,const Fraction & b){
    int gcd_a=Gcd(a.numerator,a.denominator);
    int gcd_b=Gcd(b.numerator,b.denominator);
    return (a.numerator/gcd_a)*(b.denominator/gcd_b)==(b.numerator/gcd_a)*(a.denominator/gcd_b);}
const bool operator>=(const Fraction & a,const Fraction & b){
    int gcd_a=Gcd(a.numerator,a.denominator);
    int gcd_b=Gcd(b.numerator,b.denominator);
    return (a.numerator/gcd_a)*(b.denominator/gcd_b)>=(b.numerator/gcd_a)*(a.denominator/gcd_b);}

const bool operator>(const Fraction & a,const Fraction & b){
    int gcd_a=Gcd(a.numerator,a.denominator);
    int gcd_b=Gcd(b.numerator,b.denominator);
    return (a.numerator/gcd_a)*(b.denominator/gcd_b)>(b.numerator/gcd_a)*(a.denominator/gcd_b);}
const bool operator<=(const Fraction & a,const Fraction & b){
    int gcd_a=Gcd(a.numerator,a.denominator);
    int gcd_b=Gcd(b.numerator,b.denominator);
    return (a.numerator/gcd_a)*(b.denominator/gcd_b)<=(b.numerator/gcd_a)*(a.denominator/gcd_b);}
const bool operator<(const Fraction & a,const Fraction & b){
    int gcd_a=Gcd(a.numerator,a.denominator);
    int gcd_b=Gcd(b.numerator,b.denominator);
    return (a.numerator/gcd_a)*(b.denominator/gcd_b)<(b.numerator/gcd_a)*(a.denominator/gcd_b);}



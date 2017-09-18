// rational.h
#include <iostream>
class Rational {
    friend std::ostream& operator<<(std::ostream &, Rational &);
    friend std::istream& operator>>(std::istream &, Rational &);
  public:
    Rational();
    Rational(int, int);
    ~Rational();
    
    void setRational(int, int);

    int getNumer();
    int getDenom();
    void setNumer(int);
    void setDenom(int);
    void print();
    
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);
  private:
    int numer;
    int denom;
};


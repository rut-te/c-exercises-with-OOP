#pragma once
class Rational
{
private:
	int numerator;//The numerator part of the rational number
	int denominator;//The part of the denominator in the rational number
public:
	void setNumerator(int myNumerator);//numerator initialization
	int getNumerator();//Return a numerator value 
	void setDenominator(int myDenominator);//denominator initialization
	int getDenominator();//Return a denominator value 
	void print();//A function that prints the resulting fraction
	bool equal(Rational num);//A function that compares 2 received fractions
	void reduction();//A function that reduces the fraction
	Rational add (Rational num);//A function that connects 2 fractions and returns the reduced fraction
	Rational(int numerator=0, int denominator=1);//constructor
	Rational operator+(const Rational& num) const;//operator +
	Rational operator-(const Rational& num) const;//operator -
	Rational operator*(const Rational& num) const;//operator *
	Rational operator/(const Rational& num) const;//operator /
	Rational operator++();//operator ++ in the start
	Rational operator++(int notused);//operator ++ in the end
	Rational operator--();//operator -- in the start
	Rational operator--(int notused);//operator -- in the end
	bool operator>=(const Rational& num) const;//operator >=
	bool operator<=(const Rational& num) const;//operator <=
	bool operator>(const Rational& num) const;//operator >
	bool operator<(const Rational& num) const;//operator <
	bool operator==(const Rational& num) const;//operator ==
	bool operator!=(const Rational& num) const;//operator !=
};


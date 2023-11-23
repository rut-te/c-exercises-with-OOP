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
	Rational add(Rational num);//A function that connects 2 fractions and returns the reduced fraction
};


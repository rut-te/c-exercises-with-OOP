#include "Rational.h"
#include<iostream>
using namespace std;

void Rational::setNumerator(int myNumerator)//realization numerator initialization
{
	numerator = myNumerator;
}

int Rational::getNumerator()//realization Return a numerator value
{
	return numerator;
}

void Rational::setDenominator(int myDenominator)//realization denominator initialization
{
	if (myDenominator != 0)//Checking that the denominator is not zero, in case the denominator is zero, a one is placed in it
		denominator = myDenominator;
	else
	{
		cout << "ERROR" << endl;
		denominator = 1;
	}

}

int Rational::getDenominator()//realization Return a denominator value 
{
	return denominator;
}

void Rational::print()//realization function that prints the resulting fraction
{
	cout << numerator << "/" << denominator;
}

bool Rational::equal(Rational num)//realization function that compares 2 received fractions
{
	if (num.numerator == numerator && num.denominator == denominator)//Equality check between numerators and denominators
		return true;
	return false;
}

void Rational::reduction()//realization function that reduces the fraction
{
	if (numerator == 0)//If the numerator is zero, reduce the denominator to one
		denominator = 1;
	else
	{
		int min;
		if (numerator <= denominator)//Checking which is the largest tax that can be made a common denominator with.
			min = numerator;
		else
			min = denominator;
		int i = 1;
		for (i = min; i > 1; i--)//From the largest number we found, check which number from it and below has a common denominator between the 2 fractions
		{
			if (numerator % i == 0 && denominator % i == 0)
				break;
		}
		numerator /= i;//Dividing the numerator by the number we found
		denominator /= i;//Dividing the denominator by the number we found
	}
	if (denominator < 0)
	{
		denominator = denominator * (-1);
		numerator = numerator * (-1);
	}
}

Rational Rational::add(Rational num)//realization function that connects 2 fractions and returns the reduced fraction
{
	Rational num2;
	num2.numerator = numerator * num.denominator + num.numerator * denominator;//Multiply each numerator by the denominator of the second fraction
	num2.denominator = denominator * num.denominator;//Multiplying the denominators
	num2.reduction();//Reducing the resulting fraction
	return num2;//Returning the reduced fraction
}

Rational::Rational(int mynumerator, int mydenominator)//constructor
{
	numerator = mynumerator;
	if (denominator != 0)
		denominator = mydenominator;
	else
	{
		denominator = 1;
		cout << "ERROR" << endl;
	}
	
}

Rational Rational::operator+(const Rational& num) const//operator +
{
	int newNumerator = numerator * num.denominator + denominator * num.numerator;
	int newDenominator = denominator * num.denominator;
	Rational newNum(newNumerator, newDenominator);
	newNum.reduction();
	return newNum;
}

Rational Rational::operator-(const Rational& num) const//operator -
{
	int newNumerator = numerator * num.denominator - denominator * num.numerator;
	int newDenominator = denominator * num.denominator;
	Rational newNum(newNumerator, newDenominator);
	newNum.reduction();
	return newNum;
}

Rational Rational::operator*(const Rational& num) const//operator *
{
	Rational newNum;
	newNum.setNumerator(numerator * num.numerator);
	newNum.setDenominator(denominator * num.denominator);
	newNum.reduction();
	return newNum;
}

Rational Rational::operator/(const Rational& num) const//operator /
{
	Rational newNum;
	newNum.setNumerator(numerator * num.denominator);
	newNum.setDenominator(denominator * num.numerator);
	newNum.reduction();
	return newNum;
}

Rational Rational::operator++()//operator ++ in the start
{
	numerator = numerator + denominator;
	return *this;
}

Rational Rational::operator++(int notused)//operator ++ in the end
{
	Rational newNum(numerator,denominator);
	numerator += denominator;
	return newNum;
}

Rational Rational::operator--()//operator -- in the start
{
	numerator = numerator - denominator;
	return *this;
}

Rational Rational::operator--(int notused)////operator -- in the end
{
	Rational newNum(numerator, denominator);
	numerator -= denominator;
	return newNum;
}

bool Rational::operator>=(const Rational& num) const//operator >=
{
	if (numerator/(float)denominator>= num.numerator / (float)num.denominator)
		return true;
	return false;
}

bool Rational::operator<=(const Rational& num) const//operator <=
{
	if (numerator / (float)denominator <= num.numerator / (float)num.denominator)
		return true;
	return false;
}

bool Rational::operator>(const Rational& num) const//operator >
{
	if (numerator / (float)denominator > num.numerator / (float)num.denominator)
		return true;
	return false;
}

bool Rational::operator<(const Rational& num) const//operator <
{
	if (numerator / (float)denominator < num.numerator / (float)num.denominator)
		return true;
	return false;
}

bool Rational::operator==(const Rational& num) const//operator ==
{
	if (numerator == num.numerator && denominator == num.denominator)
		return true;
	return false;
}

bool Rational::operator!=(const Rational& num) const//operator !=
{
	if(num==(*this))
		return false;
	return true;
}

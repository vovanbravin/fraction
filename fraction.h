#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
class fraction
{
	int numerator;
	int denominator;

	void Sorkrat();

public:
	fraction(int numerator, int denominator) :numerator{ numerator }, denominator{ denominator } {};
	fraction() :fraction(0, 1) {};
	void SetNumerator(int numerator)
	{	
		this->numerator = numerator;
	}
	void SetDenominator(int denominator)
	{
		this->denominator = denominator;
	}

	int GetNumerator() { return numerator; };
	int GetDenominator() { return denominator; };
	void InitFraction();

	void Multiplication(fraction& a, fraction& b);
	void Subtraction(fraction &a, fraction &b);
	void Addition(fraction& a, fraction& b);
	void Division(fraction& a, fraction& b);
	void ShowFraction();

};



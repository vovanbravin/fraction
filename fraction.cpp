#include "fraction.h"

void fraction::ShowFraction()
{
	if (numerator == 0 || denominator == 1)std::cout << numerator;
	else if (numerator < 0 && denominator < 0)std::cout << -numerator << "/" << -denominator;
	else std::cout << numerator << "/" << denominator;
}

void fraction::Sorkrat()
{
	for (int i = numerator; i > 0; i--)
	{
		if (numerator % i == 0 && denominator % i == 0)
		{
			numerator /= i;
			denominator /= i;
		}
	}
}

void fraction::Multiplication(fraction &a, fraction &b)
{
	numerator = (a.GetNumerator() * b.GetNumerator());
	denominator = (a.GetDenominator() * b.GetDenominator());

	Sorkrat();

}

void fraction::Subtraction(fraction& a, fraction& b)
{
	bool pro;
	std::cout << "Из какой дроби хотите вычитать?\n";
	std::cout << "Если из первой введите 0,второй - 1: ";
	std::cin >> pro;
	if (pro) std::swap(a, b);

	if (a.GetDenominator() != b.GetDenominator())
	{
		a.SetNumerator(a.GetNumerator() * b.GetDenominator());
		b.SetNumerator(b.GetNumerator() * a.GetDenominator());

		numerator = a.GetNumerator() - b.GetNumerator();
		denominator = a.GetDenominator() * b.GetDenominator();

	}

	else
	{
		numerator = a.GetNumerator() - b.GetNumerator();
		denominator = a.GetDenominator();
	}

		Sorkrat();
}

bool Proverka(std::string &x,int pol)
{
	if (x == "0" && pol == 2 || x=="-") return true;
	for (int i = 0; i < x.length(); i++)
	{
		if ((x[i]<'0' || x[i]>'9') && (x[0] != '-'))return true;
	}
	return false;
}

void fraction::InitFraction()
{
	std::string x,y;
	do {
		std::cout << "Введите числитель: ";
		getline(std::cin, x);
	} while (Proverka(x,1));
	SetNumerator(std::stoi(x));

	do {
		std::cout << "Введите знаменатель: ";
		getline(std::cin, y);
	} while (Proverka(y,2));
	SetDenominator(std::stoi(y));

}

void fraction::Addition(fraction&a,fraction&b)
{
	if (a.GetDenominator() != b.GetDenominator())
	{
		a.SetNumerator(a.GetNumerator() * b.GetDenominator());
		b.SetNumerator(b.GetNumerator() * a.GetDenominator());

		numerator = a.GetNumerator() + b.GetNumerator();
		denominator = a.GetDenominator() * b.GetDenominator();

	}
	
	else
	{
		numerator = a.GetNumerator() + b.GetNumerator();
		denominator = a.GetDenominator();
	}


	Sorkrat();
}

void fraction::Division(fraction&a,fraction&b)
{
	bool pro;
	std::cout << "Какую дробь хотите делить?\n";
	std::cout << "Если первую введите 0,вторую - 1: ";
	std::cin >> pro;
	if (pro) std::swap(a, b);

	numerator = a.GetNumerator() * b.GetDenominator();
	denominator = a.GetDenominator() * b.GetNumerator();

	Sorkrat();
}
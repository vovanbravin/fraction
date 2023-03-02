#include "fraction.h";



int main()
{
	setlocale(LC_ALL, "RUS");

	fraction a, b, result;

	a.InitFraction();

	uint32_t count;
	do {
		std::cout << "Добавить дробь - 1,целое число - 2: ";
		std::cin >> count;
	} while (count < 1 || count>2);

	if(count==1) b.InitFraction();
	else
	{
		uint32_t number;
		std::cout << "Введите число: ";
		std::cin >> number;
		fraction c(number,1);
		b = c;
	}
	int action;
	do {
		std::cout << "\t\tМеню:\n"
			<< "\tВычитание - 1\n"
			<< "\tСложение - 2\n"
			<< "\tДеление - 3\n"
			<< "\tУмножение - 4\n";
		std::cin >> action;
	} while (action < 1 || action>4);

	enum action { subtraction = 1, addition, division, multiplication};

	switch (action)
	{
	case subtraction:
		result.Subtraction(a, b);
		break;
	case addition:
		result.Addition(a, b);
		break;
	case division:
		result.Division(a,b);
		break;
	case multiplication:
		result.Multiplication(a, b);
		break;

	default:
		break;
	}
	std::cout<<std::endl;
	std::cout << "Ответ: ";
	result.ShowFraction();

	return 0;
}

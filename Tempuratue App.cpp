#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

enum enTemperatureChoices
{
	Celsius = 1,
	Fahrenheit = 2,
	Kelvin = 3,
	Exit = 4
};

struct stTempValues
{
	enTemperatureChoices tempFrom{};
	enTemperatureChoices tempTo{};
	double tempValue = 0.0;
};

enTemperatureChoices readConvertTemp(int from, int to, bool hasExit = true)
{
	int choice = 0;

	cout << "\t[1] Celsius\n";
	cout << "\t[2] Fahrenheit\n";
	cout << "\t[3] Kelvin\n";
	cout << (hasExit ? "\t[4] Exit\n" : "\n");
	cout << "\n\tYour Choice : ";

	while (!(cin >> choice) || choice<from || choice>to)
	{
		cout << "\n\tSorry Either out of range or invalid datatype inserted, please enter a valid number from " << from << " To " << to << " : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return static_cast<enTemperatureChoices>(choice);
}

void printHeader()
{
	cout << "\n\t=========================================\n";
	cout << "\t	Temperature Converter";
	cout << "\n\t=========================================\n";
}

double readTempValue()
{
	double value = 0;

	cout << "\n\tEnter Temperature Value : ";
	
	while (!(cin >> value))
	{
		cout << "\n\tInvalid Datatyped, Please enter a number : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return value;
}

double convert(const stTempValues& stValues)
{
	switch (stValues.tempFrom)
	{
	case enTemperatureChoices::Celsius:
		switch (stValues.tempTo)
		{
		case enTemperatureChoices::Fahrenheit:
			return (stValues.tempValue * 9 / 5) + 32;
		case enTemperatureChoices::Kelvin:
			return (stValues.tempValue + 273.15);
		default:
			return stValues.tempValue;
		}
	case enTemperatureChoices::Fahrenheit:
		switch (stValues.tempTo)
		{
		case enTemperatureChoices::Celsius:
			return (stValues.tempValue - 32) * 5 / 9;
		case enTemperatureChoices::Kelvin:
			return (stValues.tempValue - 32) * 5 / 9 + 273.15;
		default:
			return stValues.tempValue;
		}
	case enTemperatureChoices::Kelvin:
		switch (stValues.tempTo)
		{
		case enTemperatureChoices::Celsius:
			return stValues.tempValue - 273.15;
		case enTemperatureChoices::Fahrenheit:
			return (stValues.tempValue - 273.15) * 9 / 5 + 32;
		default:
			return stValues.tempValue;
		}
	default:
		return 0;
	}
}

string tempStringFormat(enTemperatureChoices C)
{
	switch (C)
	{
	case enTemperatureChoices::Celsius:
		return "Celisius";
	case enTemperatureChoices::Fahrenheit:
		return "Fahrenheit";
	case enTemperatureChoices::Kelvin:
		return "Kelvin";
	default:
		return "";
	}
}

void playRound()
{
	stTempValues stValues{};

	cout << "\n\tConvert From : \n";
	stValues.tempFrom = readConvertTemp(1, 4);

	if (stValues.tempFrom == enTemperatureChoices::Exit)
		return;

	cout << "\n\tConvert To : \n";
	stValues.tempTo = readConvertTemp(1, 3, false);

	stValues.tempValue = readTempValue();
	double conversion = convert(stValues);

	cout << "\n\t " << stValues.tempValue << " " << tempStringFormat(stValues.tempFrom) << " = ";
	cout << fixed << setprecision(2) << conversion;
	cout << " " << tempStringFormat(stValues.tempTo);
}

void playConversion()
{
	char again = 'y';
	printHeader();

	do {
		system("cls");
		playRound();

		cout << "\n\n\tConvert Another [y/Y] : ";
		cin >> again;

	} while (tolower(again) == 'y');
	
	cout << "\n\tGoodbye !\n\n";
}

int main()
{
	playConversion();
}
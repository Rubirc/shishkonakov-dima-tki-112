#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
* \brief Расчёт функции
* \param x Аргумент функции
* \return Значение функции
**/
double СalcFunction(const double x);

/**
* \brief Проверка на существование функции
* \param x Аргумент функции
* \return False при несуществовании функции
**/
bool NotCalculated(const double x);

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << fixed;

	const double LOWER_BOUND = 0, UPPER_BOUND = 1, STEP = 0.1;
	const int WIDTH = 5;

	cout << setw(WIDTH) << "X" << " | " << setw(2 * WIDTH) << "Y\n";

	for (double x = LOWER_BOUND; x < UPPER_BOUND; x += STEP)
	{
		if (NotCalculated(x))
			cout << setw(WIDTH) << x << " | " << setw(2 * WIDTH) << "Невозможно вычислить значение функции в данной точке.\n";
		else
			cout << setw(WIDTH) << x << " | " << setw(2 * WIDTH) << СalcFunction(x) << "\n";
	}

	return 0;
}

double СalcFunction(const double x)
{
	return sqrt(1.0 - x) - cos(sqrt(1.0 - x));
}

bool NotCalculated(const double x)
{
	return ((1.0 - x) >= 0);
}

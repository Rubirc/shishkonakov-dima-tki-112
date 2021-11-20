#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
* \brief Расчёт функции
* \param x Аргумент функции
* \return Значение функции
**/
double calcFunction(const double x);

int main()
{
	const double LOWER_BOUND = 0, UPPER_BOUND = 1, STEP = 0.1 
        const int WIDTH = 5;

	cout << setw(WIDTH) << "X" << " | " << setw(2 * WIDTH) << "Y\n";

	for (double x = LOWER_BOUND; x < UPPER_BOUND; x += STEP)
	{
		cout << setw(WIDTH) << x << " | " << setw(2 * WIDTH) << calcFunction(x) << "\n";
	}

	return 0;
}

double calcFunction(const double x)
{
	return sqrt(1.0 - x) - cos(sqrt(1.0 - x));
}

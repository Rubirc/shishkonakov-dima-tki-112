#include <iostream>
#include <math.h>

using namespace std;
/**
* \brief Функция расчета уравнение A
* \param X - Переменная уравнения
* \param Y - Переменная уравнения
* \param Z - Переменная уравнения
* \return GetA - результат уравнения А
*/
double GetA(const double x, const double y, const double z);
/* * \brief Функция расчета уравнение B
* \param X - Переменная уравнения
* \param Y - Переменная уравнения
* \param Z - Переменная уравнения
* \return GetB - результат уравнения B
*/
double GetB(const double x, const double y, const double z);

int main()
{
	const auto x = 0.5;
	const auto y = 0.05;
	const auto z = 0.7;

	const auto a = GetA(x, y, z);
	const auto b = GetB(x, y, z);

	std::cout << "x = " << x << ", y = " << y << ", z = " << z << '\n';
	std::cout << "a = " << a << ", b = " << b << endl;
	return 0;

}

double GetA(const double x, const double y, const double z)
{
	return  x * 2 * y * (x + 1) - sin(2 * (x + z));
}

double GetB(const double x, const double y, const double z)
{
	return  sqrt(x * y * z) + cos(2 * 2 * (x + y));
}
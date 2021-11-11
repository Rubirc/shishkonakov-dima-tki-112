#include <iostream>
#include <math.h>

using namespace std;
/**
* \brief ������� ������� ��������� A
* \param X - ���������� ���������
* \param Y - ���������� ���������
* \param Z - ���������� ���������
* \return GetA - ��������� ��������� �
*/
double GetA(const double x, const double y, const double z);
/* * \brief ������� ������� ��������� B
* \param X - ���������� ���������
* \param Y - ���������� ���������
* \param Z - ���������� ���������
* \return GetB - ��������� ��������� B
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
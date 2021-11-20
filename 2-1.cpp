#include <iostream>
using namespace std;
/*
* \brief увеличение числа a в n раз
* \param a число a
* \param n число n
* \return число a увеличенное в n раз
*/
const int getproduct(int a, int n);

/*
* \brief увеличение числа a в 2n раз
* \param a число a
* \param n число n
* \return число a увеличенное в 2n раз
*/
const int getdoubleproduct(int a, int n);

/*
* \brief увеличение числа a в 3n раз
* \param a число a
* \param n число n
* \return число a увеличенное в 3n раз
*/
const int gettripleproduct(int a, int n);

/*
* \brief выбор заполнения массива
*/
enum class path
{
	Single = 1,
	Double = 2,
	Triple = 3
};

/*
* \brief Точка входа в программу.
* \return Код ошибки, если 0 - успешное выполнение.
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите число A : ";
	int a;
	cin >> a;
	cout << "Введите число N : ";
	int n;
	cin >> n;
	cout << "Выберите формулу:\n1: A * N\n2: 2 * A * N\n3: 3 * A * N\nВыбор: ";
	int choice;
	cin >> choice;
	const auto filling = static_cast<path>(choice);
	switch (filling) {
	case path::Single:
		{
			cout << "A * N = " << getproduct(a, n);
			break;
		}
	case path::Double:
		{
			cout << "2 * A * N = " << getdoubleproduct(a, n);
			break;
		}
	case path::Triple:
		{
			cout << "3 * A * N = " << gettripleproduct(a, n);
			break;
		}
	default:
	{
		cout << "Некоректный ввод.";
		return (0);
	}
	}
	return 0;
}

const int getproduct(int a, int n)
{
	return (a * n);
}

const int getdoubleproduct(int a, int n)
{
	return (a * 2 * n);
}

const int gettripleproduct(int a, int n)
{
	return (a * 3 * n);
}

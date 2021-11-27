#include <iostream>
using namespace std;
/*
* \brief увеличение числа a в n раз
* \param a число a
* \param n число n
* \return число a увеличенное в n раз
*/
const int GetProduct(int a, int n);

/*
* \brief увеличение числа a в 2n раз
* \param a число a
* \param n число n
* \return число a увеличенное в 2n раз
*/
const int GetDoubleProduct(int a, int n);

/*
* \brief увеличение числа a в 3n раз
* \param a число a
* \param n число n
* \return число a увеличенное в 3n раз
*/
const int GetTripleProduct(int a, int n);

/*
* \brief выбор уравнения
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
	cout << "Choose an option:\n" << "1) Увеличение в N раз\n" << "2) Увеличение в 2N раз\n" << "3) Увеличение в 3N раз\n"  << "1 or 2 or 3: ";
	int choice;
	cin >> choice;
	const auto filling = static_cast<path>(choice);
	switch (filling) {
	case path::Single:
	{
		cout << "A * N = " << GetProduct(a, n);
		break;
	}
	case path::Double:
	{
		cout << "2 * A * N = " << GetDoubleProduct(a, n);
		break;
	}
	case path::Triple:
	{
		cout << "3 * A * N = " << GetTripleProduct(a, n);
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

const int GetProduct(int a, const int n)
{
	return (a * n);
}

const int GetDoubleProduct(int a, const int n)
{
	return (a * 2 * n);
}

const int GetTripleProduct(int a, const int n)
{
	return (a * 3 * n);
}

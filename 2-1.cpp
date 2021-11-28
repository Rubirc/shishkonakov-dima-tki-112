#include <iostream>
using namespace std;
/*
* \brief увеличение числа a в n раз
* \param a число a
* \param n число n
* \return число a увеличенное в n раз
*/
int GetProduct(const int a, const int n);

/*
* \brief увеличение числа a в 2n раз
* \param a число a
* \param n число n
* \return число a увеличенное в 2n раз
*/
int GetDoubleProduct(const int a, const int n);

/*
* \brief увеличение числа a в 3n раз
* \param a число a
* \param n число n
* \return число a увеличенное в 3n раз
*/
int GetTripleProduct(const int a, const int n);

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
    cout << "Выберете что делать дальше:\n"
        << "Введите " << static_cast<int>(path::Single) << " - для увеличения A в N раз,\n"
        << "Введите " << static_cast<int>(path::Double) << " - для увеличения A в 2N раз,\n"
        << "Введите " << static_cast<int>(path::Triple) << " - для увеличения A в 3N раз,\n"
        << "Ваш выбор: ";
    int choice;
    cin >> choice;
    const auto chosen = static_cast<path>(choice);
    switch (chosen) {
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

int GetProduct(const int a, const int n)
{
    return (a * n);
}

int GetDoubleProduct(const int a, const int n)
{
    return (a * 2 * n);
}

int GetTripleProduct(const int a, const int n)
{
    return (a * 3 * n);
}

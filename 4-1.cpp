#include <iostream>
#include <string>
#include <random>
#include <sstream>

using namespace std;

/**
* \brief Заполнение массива случайными числами
* \array Массив
* \size Размер массива
* \param min Минимально возможное число
* \param max Максимально возможное число
**/
void randomizeArray(int* array, const size_t size, const int min, const int max);

/**
* \brief Ввод массива с клавиатуры
* \param array Массив
* \param size Размер массива
**/
void manualInput(int* array, const size_t size);

/**
* \brief Конвертация массива строку вида {element_1, element_2, ... ,element_n}
* \param array Массив
* \param size Размер массива
* \param message Сообщение, которое будет выведено перед массивом
**/
string arrayToString(int* array, const size_t size, const string& message = "");

/**
* \brief Определяет чётное ли число
* \param number Число, которое необходимо проверить
* \return True если чётное
**/
bool isEven(const int number);

/**
* \brief Определяет делится ли число на делитель
* \param number Число, которое необходимо проверить
* \param divider Делитель
* \return True если чётное
**/
bool isDivisible(const int number, const int divider);

/**
* \brief Считает сумму чётных отрицательных элементов
* \param arr Массив
* \param size Размер массива
* \return Сумма элементов
**/
int calcSum(int* arr, const size_t size);

/**
* \brief Записывает индексы элементов, делящихся на 3 и 6
* \param arr Массив
* \param size Размер массива
* \return Строка индексов
**/
string showIndexes(int* arr, const size_t size);

/**
* \brief Поиск индекс максимального элемента массива
* \param arr Массив
* \param size Размер массива
* \return Индекс максимального элемента
**/
size_t findIndexOfMax(const int* arr, const size_t size);

/**
* \brief Поиск индекс минимального элемента массива
* \param arr Массив
* \param size Размер массива
* \return Индекс минимального элемента
**/
size_t findIndexOfMin(const int* arr, const size_t size);

/**
* \brief Замена элементов массива на 0 между максимальным и минимальным
* \param arr Массив
* \param size Размер массива
**/
void replaceElements(int* arr, const size_t size);

/**
* \brief Выбор заполнеия массива
**/
enum class FillType
{
    randomize = 1,
    manual = 2
};

int main()
{
    const int MIN = -1000, MAX = 1000;

    cout << "Please input array length: ";
    size_t size;
    cin >> size;

    int* arr = new int[size];

    cout << "Choose an option:\n" << "1) Generate array\n" << "2) Manual input\n" << "1 or 2: ";
    int choice;
    cin >> choice;

    const auto fillType = static_cast<FillType>(choice);

    switch (fillType)
    {
    case FillType::randomize:
    {
        randomizeArray(arr, size, MIN, MAX);
        cout << arrayToString(arr, size, "Your array = ") << "\n";
        break;
    }
    case FillType::manual:
    {
        manualInput(arr, size);
        break;
    }
    default:
        break;
    }

    cout << "Сумма чётных отрицательных элементов: " << calcSum(arr, size) << "\n";

    cout << "Индексы элементов, кратных 3 и 6: " << showIndexes(arr, size) << "\n";

    replaceElements(arr, size);
    cout << "Замена нулями между минимальным и максимальным: " << arrayToString(arr, size) << "\n";

}

void randomizeArray(int* array, const size_t size, const int min, const int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    const uniform_int_distribution<> uniformIntDistribution(min, max);

    for (size_t i = 0; i < size; ++i)
        array[i] = uniformIntDistribution(gen);

}

void manualInput(int* array, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << "array[" << i << "] = ";
        cin >> array[i];
    }
}

string arrayToString(int* array, const size_t size, const string& message)
{
    std::stringstream buffer;
    buffer << message << "{" << array[0];

    for (size_t i = 1; i < size; ++i)
    {
        buffer << ", " << array[i];
    }

    buffer << "}";

    return buffer.str();
}

bool isEven(const int number)
{
    return number % 2 == 0;
}

bool isDivisible(const int number, const int divider)
{
    return number % divider == 0;
}

int calcSum(int* arr, const size_t size)
{
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0 && isEven(arr[i]))
            sum += arr[i];
    }

    return sum;
}

string showIndexes(int* arr, const size_t size)
{
    std::stringstream buffer;

    for (size_t i = 0; i < size; i++)
    {
        if (isDivisible(arr[i], 3) && isDivisible(arr[i], 6))
            buffer << i << " ";
    }


    return buffer.str();
}

size_t findIndexOfMax(const int* arr, const size_t size)
{
    size_t indexOfMax = 0;

    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] > arr[indexOfMax])
            indexOfMax = i;
    }

    return indexOfMax;
}

size_t findIndexOfMin(const int* arr, const size_t size)
{
    size_t indexOfMin = 0;

    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] < arr[indexOfMin])
            indexOfMin = i;
    }

    return indexOfMin;
}

void replaceElements(int* arr, const size_t size)
{
    size_t lowerIndex = min(findIndexOfMax(arr, size), findIndexOfMin(arr, size));
    size_t upperIndex = max(findIndexOfMax(arr, size), findIndexOfMin(arr, size));

    for (size_t i = lowerIndex + 1; i < upperIndex; i++)
        arr[i] = 0;

}

#include <iostream>
#include <ctime>
#include <random>

#include "array.h"

int getLenghtUser()
{
    printf("Введите длину массива: ");
    int length;

    scanf("%d", &length);
    std::cin.ignore(32767, '\n');

    return length;
}

int getLenghtRandom(int minN, int maxN)
{
    try
    {
        if (minN < 0)
            throw minN;
    }
    catch (int minN)
    {
        std::cerr << "ОШИБКА(minN =" << minN << "):minN должен быть > 0. ";
    }

    std::mt19937 engine(static_cast<unsigned long>(clock()));
    std::uniform_int_distribution<int> random(minN, maxN);
    return random(engine);
}

int getIndexUser(const int numberElementsArray, const char *reason)
{
    printf("Введите индекс (%s): ", reason);
    int index;
    scanf("%d", &index);
    while (true)
    {
        if (index < 0 && index > numberElementsArray)
        {
            printf("Введен некорректный индекс. Он должен быть числом от 0 до %d", numberElementsArray);
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return index;
        }
    }
}

int getElementUser(const char *reason)
{
    int element;

    printf("Введите элемент (%s): ", reason);
    scanf("%d", &element);
    std::cin.ignore(32767, '\n');

    return element;
}

int *generateFromUser(int *array, int numberElements)
{
    printf("Введите элементы массива через пробел: ");

    for (int i = 0; i < numberElements; i++)
    {
        int value;
        scanf("%d", &value);
        array[i] = value;
    }
    std::cin.ignore(32767, '\n');
    return array;
}

int *generateRandom(int *array, int numberElements, int minNumber, int maxNumber)
{
    std::mt19937 engine(static_cast<unsigned long>(clock()));
    std::uniform_int_distribution<int> random(minNumber, maxNumber);

    for (int i = 0; i < numberElements; i++)
    {
        array[i] = random(engine);
    }

    return array;
}

int searchElement(const int *array, const int numberElements, const int number)
{
    for (int i = 0; i < numberElements; i++)
    {
        if (array[i] == number)
            return i;
    }
    return -1;
}

int searchMinMaxElement(const int *array, int numberElements, bool comparator(int, int))
{
    int firstNumber = *array;
    int result = 0;

    for (int i = 1; i < numberElements; i++)
    {
        if (comparator(firstNumber, array[i]))
        {
            firstNumber = array[i];
            result = i;
        }
    }
    return result;
}

int searchMinMaxElementWithConditions(const int *array, int numberElements, bool comparator(int, int), bool condition(int))
{
    int firstNumber = *array;
    int result = 0;

    for (int i = 1; i < numberElements; i++)
    {
        array++;
        int secondNumber = *array;
        if (comparator(firstNumber, secondNumber))
        {
            if (condition(secondNumber))
            {
                firstNumber = secondNumber;
                result = i;
            }
        }
    }
    return result;
}

int *searchIndexElements(const int *array, const int numberElements, const int number)
{
    int *arrayResult = new int[numberElements];

    for (int i = 0, iResArray = 1; i < numberElements; i++)
    {
        if (array[i] == number)
        {
            arrayResult[iResArray] = i; //Заполняем arrayResult
            arrayResult[0] = iResArray; //Записываем длину массива в 1 элемент

            iResArray++;
        }
    }
    if (arrayResult[0] == -1)
        return nullptr;
    else
        return arrayResult;
}

int *elementsAppropriateConditions(int *array, int numberElements, bool *condition(int number))
{
    int *arrayResult = new int[numberElements];

    for (int counterArray = 0, iteratorResult = 1; counterArray < numberElements; counterArray++)
    {
        if (condition(*array))
        {
            arrayResult[iteratorResult] = *array;
            arrayResult[0] = iteratorResult;
            iteratorResult++;
        }
        array++;
    }

    if (arrayResult[0] == -1)
        return nullptr;
    else
        return arrayResult;
}

int *deleteElement(int *array, int numberElements, int index)
{
    int *arrayResult = new int[numberElements];

    for (int i = 0, iRes = 0; i < numberElements; i++)
    {
        if (i != index)
        {
            arrayResult[iRes] = array[i];
            iRes++;
        }
    }

    delete[] array;

    return arrayResult;
}

int *deleteCoincidences(int *array, int numberElements, int element)
{
    int *arrayResult = new int[numberElements];

    for (int i = 0, iRes = 0; i < numberElements; i++)
    {
        if (*array != element)
        {
            arrayResult[iRes] = array[i];
            iRes++;
        }
    }

    delete[] array;

    return arrayResult;
}

int *pasteElement(int *array, int numberElements, int index, int element)
{
    int *arrayResult = new int[numberElements + 1];
    //i = iterator
    for (int i = 0, iRes = 0; i < numberElements; i++)
    {
        if (i == index)
        {
            arrayResult[iRes] = element;
            iRes++;
        }
        arrayResult[iRes] = *array;
        iRes++;
        array++;
    }

    return arrayResult;
}

void print(const int *array, const int numberElements, const char *text, const int offset)
{
    array = (array + offset);
    printf("Значения массива %s : [ ", text);
    for (int i = 0; i < numberElements; i++)
    {
        printf("%d, ", *array);
        array++;
    }
    printf("\b\b ]\n");
}

bool isMax(const int a, const int b)
{
    return (a < b);
}

bool isMin(const int a, const int b)
{
    return (a > b);
}

bool isOdd(const int number)
{
    return (number % 2 == 1);
}

bool isEven(const int number)
{
    return (number % 2 == 0);
}
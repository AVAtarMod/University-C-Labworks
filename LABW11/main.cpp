#include <iostream>

#include "arrays2d.h"
#include "array.h"

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();
void task10();
void task11();
void task12();

int main(int argc, char const *argv[])
{
    bool noData = false;
    if (argc == 1)
    {
        printf("Введите программу для запуска: ");
        argc++;
        noData = true;
    }
    for (int i = 1; i < argc; i++)
    {
        int choice;
        if (noData)
        {
            scanf("%d", &choice);
            std::cin.ignore(32767, '\n');
        }
        else
        {
            choice = std::stoi(argv[i]);
        }

        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 9:
            task9();
            break;
        case 10:
            task10();
            break;
        case 11:
            task11();
            break;
        case 12:
            task12();
            break;

        default:
            printf("Номер задачи введен не верно либо не удалось конвертировать введенные данные");
            break;
        }
    }
}

void task1()
{
    int rows = 10, collumns = 10;
    int **array = array2d::init(rows, collumns);

    int sum = 0;
    for (int r = 0; r < rows; r++)
    {
        sum = r - 1;
        for (int c = 0; c < collumns; c++)
        {
            sum = (sum < 9) ? sum + 1 : 0;
            array[r][c] = sum;
        }
    }

    array2d::print(array, collumns, rows, "для №1 задания", 9);

    delete[] array;
}
void task2()
{
    int *range = array2d::getRangeUser();
    int *size = array2d::getSizeUser();
    int **array = array2d::init(size[0], size[1]);
    array = array2d::fillRandom(array, range[0], range[1], size[0], size[1]);
    array2d::print(array,size[0],size[1],"",range[1]);

    printf("Введите элемент чтобы найти количество его вхождений: ");
    int element;
    scanf("%d",&element);
    std::cin.ignore(32767,'\n');

    int numOfOccurences=0;
    for (int row = 0; row < size[0]; row++)
    {
        for (int col = 0; col < size[1]; col++)
        {
            if(array[row][col] == element){
                numOfOccurences++;
            }
        }
    }
    
    if (numOfOccurences > 0) printf("\nЭлемент встречается %d раз(а)\n",numOfOccurences);
    else printf("\nВхождений не найдено.\n");

    delete[] array;
    delete[] size;
    delete[] range;

}
void task3()
{

}
void task4()
{
}
void task5()
{
}
void task6()
{
}
void task7()
{
}
void task8()
{
}
void task9()
{
}
void task10()
{
}
void task11()
{
}
void task12()
{
}
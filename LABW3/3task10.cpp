//целые числа n и k имеют одинаковую четность;

#include <iostream>
#include <math.h>

int main(){
    using namespace std;

    int n,k,res1,res2;
    printf("\n\nВведите n,k через пробел.Пример:1 2\n");
    scanf("%d %d",&n,&k);

    if (n % 2 == k % 2)
    {
        printf("\nTrue\n\n");
    }
    else
    {
        printf("\nFalse\n\n");
    }

    /* Проверка обоих чисел на нечетность и последующая проверка на то,
    что n и k имеют одинаковую четность
    Если хотя бы одно число = 0,то результат всегда True т.к 0
    и четен и нечетен (делится без остатка на любое число)
    */

    return 0;
}
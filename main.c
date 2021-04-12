#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1 == 1
#define false 1 != 1
#define bool int

void ex15_1();
unsigned long simpleHash(const char* str);

void ex15_2();
int* exchange(int* money, int size, int sum);
bool isSortedByDesc(int* money, int size);
void sortInsertsDesc(int* money, int first, int last);


int main()
{
    ex15_1();
    ex15_2();

    return 0;
}

void ex15_1()
{
    printf("Exercise 15.1\n");
    const int strSize = 1024;
    char* str = (char*)malloc(strSize * sizeof(char));

    printf("Enter string: ");

    fgets(str, strSize, stdin);

    if ((strlen(str) > 0) && (str[strlen(str) - 1] == '\n'))
        str[strlen(str) - 1] = '\0';

    printf("Sum of character codes = %ld\n", simpleHash(str));

    free(str);
}

unsigned long simpleHash(const char* str)
{
    unsigned long sum = 0;

    while (*str)
        sum += *str++;

    return sum;
}

void ex15_2()
{
    printf("\nExercise 15.2\n");

    int sum = 98;

    int money[] = { 50, 10, 5, 2, 1 };
    int size = sizeof(money) / sizeof(int);

    printf("There are coins: ");
    for (int i = 0; i < size; i++)
        printf("%d ", money[i]);
    printf("\n");


    if (!isSortedByDesc(money, size))
        sortInsertsDesc(money, 0, size - 1);

    int* moneyList = exchange(money, size, sum);
    int minimalCountOfCoins = *moneyList - 1;

    printf("Minimal count of coins for %d kopecks: %d\n", sum, minimalCountOfCoins);

    printf("Coins: ");
    for (int i = 1; i < minimalCountOfCoins + 1; i++)
        printf("%d ", moneyList[i]);
    printf("\n");

    free(moneyList);
}

int* exchange(int* money, int size, int sum)
{
    const int countOfCoins = 100;

    int* moneyList = (int*)calloc(countOfCoins, sizeof(int));
    int j = 1;

    for (int i = 0; i < size; i++)
        while (sum >= money[i])
        {
            sum -= money[i];
            moneyList[j++] = money[i];
        }

    *moneyList = j;

    return moneyList;
}

bool isSortedByDesc(int* money, int size)
{
    if (!money)
        return true;
    int i = 0;

    while (i < size)
    {
        if (money[i] < money[i + 1])
            return false;
        i++;
    }

    return true;
}


void sortInsertsDesc(int* money, int first, int last)
{
    int temp, pos;
    for(int i = first + 1; i <= last; i++)
    {
        temp = money[i];
        pos = i - 1;
        while(pos >= 0 && money[pos] < temp)
        {
            money[pos + 1] = money[pos];
            pos--;
        }
        money[pos + 1] = temp;
    }
}

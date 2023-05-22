#include <stdio.h>
#include <stdlib.h>

// Функція для обчислення суми елементів масиву
double calculateSum(double *array, int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    return sum;
}

// Функція для обчислення модуля числа
double absoluteValue(double num)
{
    if (num < 0)
    {
        return -num;
    }
    return num;
}

int main()
{
    int n;
    printf("Введіть натуральне число n: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Помилка введення числа. Перевірте правильність вводу.\n");
        return 1;
    }

    // Виділення пам'яті для масиву
    double *array = (double *)malloc(n * sizeof(double));
    if (array == NULL)
    {
        printf("Помилка виділення пам'яті.\n");
        return 1;
    }

    printf("Введіть %d дійсних чисел:\n", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%lf", &array[i]) != 1)
        {
            printf("Помилка введення числа. Перевірте правильність вводу.\n");
            free(array); // Звільнення пам'яті у випадку помилки
            return 1;
        }
    }

    printf("Елементи масиву:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf ", array[i]);
    }
    printf("\n");

    // Обчислення суми елементів масиву та її модуля
    double sum = calculateSum(array, n);
    double absoluteSum = absoluteValue(sum);

    printf("Результат: %.2lf\n", absoluteSum);

    free(array); // Звільнення виділеної пам'яті

    return 0;
}

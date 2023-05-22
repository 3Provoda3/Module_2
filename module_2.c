#include <stdio.h>
#include <stdlib.h>

int readArray(int *array, int n) {
    printf("Введіть %d цілих чисел:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &array[i]) != 1) {  // Зчитування цілого числа з консолі
            printf("Помилка введення числа. Перевірте правильність вводу.\n");
            return 0;  // Повертаємо 0, щоб позначити помилку
        }
    }
    return 1;  // Повертаємо 1, якщо зчитування пройшло успішно
}

void printArray(int *array, int n) {
    printf("Елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int countPositive(int *array, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] > 0) {  // Перевірка, чи є елемент додатним
            count++;
        }
    }
    return count;
}

int compareArrays(int *array1, int *array2, int n) {
    int count1 = countPositive(array1, n);  // Кількість додатних елементів у першому масиві
    int count2 = countPositive(array2, n);  // Кількість додатних елементів у другому масиві

    if (count1 > count2) {
        return 1;  // Перший масив має більше додатних елементів
    } else if (count2 > count1) {
        return 2;  // Другий масив має більше додатних елементів
    } else {
        return 0;  // Обидва масиви мають однакову кількість додатних елементів
    }
}

int main() {
    int n;
    printf("Введіть натуральне число n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {  // Зчитування натурального числа з консолі
        printf("Помилка введення числа. Перевірте правильність вводу.\n");
        return 1;  // Повертаємо 1, щоб позначити помилку
    }

    int *array1 = (int*) malloc(n * sizeof(int));  // Виділення пам'яті для першого масиву
    int *array2 = (int*) malloc(n * sizeof(int));  // Виділення пам'яті для другого масиву
    if (array1 == NULL || array2 == NULL) {  // Перевірка на успішне виділення пам'яті
        printf("Помилка виділення пам'яті.\n");
        return 1;  // Повертаємо 1, щоб позначити помилку
    }

    if (!readArray(array1, n) || !readArray(array2, n)) {  // Зчитування елементів масивів
        free(array1);  // Звільнення пам'яті першого масиву
        free(array2);  // Звільнення пам'яті другого масиву
        return 1;  // Повертаємо 1, щоб позначити помилку
    }

    printArray(array1, n);  // Виведення першого масиву на екран
    printArray(array2, n);  // Виведення другого масиву на екран

    int result = compareArrays(array1, array2, n);  // Порівняння масивів
    if (result == 1) {
        printf("Масив 1 має більше додатних значень ніж Масив 2.\n");
    } else if (result == 2) {
        printf("Масив 2 має більше додатних значень ніж Масив 1.\n");
    } else {
        printf("Масив 1 та Масив 2 мають однакову кількість додатних значень.\n");
    }

    free(array1);  // Звільнення пам'яті першого масиву
    free(array2);  // Звільнення пам'яті другого масиву

    return 0;  // Повертаємо 0, щоб позначити успішне завершення програми
}

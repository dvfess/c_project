#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define _ separator();
#define N 10
#define maxValue 30

// 1. Реализовать сортировку подсчётом.
// 2. Реализовать быструю сортировку.
// 3. *Реализовать сортировку слиянием.
// 4. **Реализовать алгоритм сортировки со списком.
// 5. Проанализировать время работы каждого из вида сортировок для 100, 10000, 1000000
// элементов. Заполнить таблицу.
// Дмитрий Волков

void swap(int *a, int *b) {
	int c;
	c = *a, *a = *b, *b = c;
}

//Заполняет массив размера size произвольными целыми числами
void fill_massive(int size, int *arr) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % maxValue;
}

//Копирует массив src в массив dst.
void copy_massive(int size, int *src, int *dst) {
	for (int i = 0; i < size; i++)
		dst[i] = src[i];
}


void print_massive(int size, int *arr) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Сортировка подсчётом
void count_sort(int size, int *arr) {
	int c[maxValue];

	// Обнуляем массив
	for (int i = 0; i < maxValue; i++)
		c[i] = 0;

	// Организуем частотный массив "c" по arr
	for (int i = 0; i < size; i++)
		c[arr[i]]++;

	printf("arr massive:\n");
	print_massive(size, arr);
	printf("частотный массив:\n");
	print_massive(maxValue, c);

	// Заполняем массив arr количеством повторений из частотного массива
	for (int arrIndex = 0; arrIndex < size; arrIndex++)
	{
		for (int cIndex = 0; cIndex < maxValue; cIndex++)
		{
			// Ищу значение !=0 в c[]
			// В arr, попадает cIndex, c[cIndex] раз.
			int i = 0;
			for (; i < c[cIndex]; i++)
			{
				arr[i + arrIndex] = cIndex;
			}
			arrIndex += i;
		}
	}
}

// Быстрая сортировка
void hoar_sort(int *arr, int left, int right)
{
	int i = left, j = right;
	int d;
	int x = arr[(left + right) / 2];
	while (i <= j) {
		while(arr[i] < x) i++;
		while(arr[j] > x) j--;
		if (i <= j) {
			d = arr[i];
			arr[i++] = arr[j];
			arr[j--] = d;
		}
	}
	if (left < j) hoar_sort(arr, left, j);
	if (i < right) hoar_sort(arr, i, right);

}


void separator() {
	printf("\n");
	for (int i = 0; i < 80; i++)
		printf("-");
	printf("\n");
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int srcArray[N]; // Эталонный массив
	int workArray[N]; // копия эталонного массива для демонстрации
	fill_massive(N, &srcArray);
	copy_massive(N, &srcArray, &workArray);
	printf("Быстрая сортировка:\n");
	printf("Массив до сортировки:\n");
	print_massive(N, &workArray);
	hoar_sort(&workArray, 0, N - 1);
	printf("Отсортированный массив:\n");
	print_massive(N, &workArray);
	_
	printf("Сортировка подсчётом:\n");
	copy_massive(N, &srcArray, &workArray);
	printf("Массив до сортировки:\n");
	print_massive(N, &workArray);
	count_sort(N, &workArray);
	printf("Отсортированный массив:\n");
	print_massive(N, &workArray);
	return 0;
}

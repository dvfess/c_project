#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define _ separator();
#define N 10

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

//Заполняет массив размера size произвольными целыми числами
void fill_massive(int size, int *arr) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 30;
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

int main()
{
	setlocale(LC_ALL, "Rus");
	int srcArray[N];
	int workArray[N];
	fill_massive(N, &srcArray);
	print_massive(N, &srcArray);
	copy_massive(N, &srcArray, &workArray);
	printf("workArray before sort:\n");
	print_massive(N, &workArray);
	printf("sorting...\n");
	hoar_sort(&workArray, 0, N - 1);
	printf("workArray after sort:\n");
	print_massive(N, &workArray);
	return 0;
}

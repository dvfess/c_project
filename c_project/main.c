#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include "sorters.c"
#include "finders.c"

#define _ separator();
#define MaxN 100

void separator() {
	for (int i = 0; i < 80; i++)
		printf("-");
	puts("\n");
}

void print(int N, int *a) {
	for (int i = 0; i < N; i++)
		printf("%4i", a[i]);
	printf("\n");
}

void sol1(int len, int *a) {
	/*1.  Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций
		  сравнения оптимизированной и неоптимизированной программы. Написать функции
		  сортировки, которые возвращают количество операций.
		Дмитрий Волков
	*/
	int wkArr[MaxN];
	memcpy(wkArr, a, sizeof(wkArr));

	puts("Bubble sort");
	puts("Исходный массив");
	print(len, wkArr);
	printf("Не оптимизированная сортировка пузырьком. Количество операций: %i\n", bubbleSort(len, wkArr));
	print(len, wkArr);

	memcpy(wkArr, a, sizeof(wkArr)); // Исходный массив
	printf("Оптимизированная сортировка пузырьком. Количество операций: %i\n", optBubbleSort(len, wkArr));
	print(len, wkArr);

}

void sol2(int len, int *a) {
	/*2. *Реализовать шейкерную сортировку*/
	puts("Shaker");
	int wkArr[MaxN];
	puts("Исходный массив");
	memcpy(wkArr, a, sizeof(wkArr));
	print(len, wkArr);
	printf("Шейкерная сортировка. Количество операций: %i\n", shakeIt(len, wkArr));
	print(len, wkArr);

}

void sol3(int len, int *a) {
	/* 3. Реализовать бинарный алгоритм поиска в виде функции, которой передаётся отсортированный
		  массив. Функция возвращает индекс найденного элемента или –1, если элемент не найден.*/	puts("Binary search");
	int wkArr[MaxN];
	memcpy(wkArr, a, sizeof(wkArr));	optBubbleSort(len, wkArr);	puts("Исходный массив");	print(len, wkArr);	int findFor = 47;	printf("idx of %i is %i", findFor, binary(findFor, len, wkArr));
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Rus");
	int srcArray[MaxN];
	int arrLen;
	errno_t err;
	FILE *in;

	if ((err = fopen_s(&in, ".\\data.txt", "r")) == 0) {
		fscanf_s(in, "%i", &arrLen);
		for (int i = 0; i < arrLen; i++) {
			fscanf_s(in, "%i", &srcArray[i]);
		}
		fclose(in);

		// Первое задание
		sol1(arrLen, srcArray);
		_
		// Второе задание
		sol2(arrLen, srcArray);
		_
		// Третье задание
		sol3(arrLen, srcArray);

	}
	else {
		fprintf(stderr, "cannot open file");
	}

	return 0;
}
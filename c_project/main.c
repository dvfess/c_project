#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define _ separator();
#define N 10

// 1. Написать функции, которые считывают матрицу смежности из файла и выводят
//    её на экран.
// 2. Написать рекурсивную функцию обхода графа в глубину.
// 3. Написать функцию обхода графа в ширину.
// Дмитрий Волков


// Загружаем матрицу смежности. Возвращаем размер матрицы или код ошибки:
// -1 - ошибка загрузки файла
// -2 - размер матрицы в файле больше, чем задан в переменной N
int load(char* filename, int W[N][N]) {
	FILE *file;
	errno_t err;
	int a;
	err = fopen_s(&file, filename, "r");
	if (file == NULL) {
		printf("Не могу открыть файл");
		fclose(file);
		return -1;
	}

	int size; // Размер матрицы
	fscanf_s(file, "%d", &size);
	if (size > N) {
		printf("Слишком большая матрица.");
		fclose(file);
		return -2;
	}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			fscanf_s(file, "%d", &a);
			W[i][j] = a;
		}
	fclose(file);
	return size;
}

void print_matrix(int size, int mt[N][N]) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d ", mt[i][j]);
		printf("\n");
	}
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
	int cMatrix[N][N];
	int size = load("data.txt", cMatrix);
	print_matrix(size, cMatrix);
	return 0;
}

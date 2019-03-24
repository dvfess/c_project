#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define _CRT_SECURE_NO_WARNINGS
#define _ separator();

// 1. Реализовать сортировку подсчётом.
// 2. Реализовать быструю сортировку.
// 3. *Реализовать сортировку слиянием.
// 4. **Реализовать алгоритм сортировки со списком.
// 5. Проанализировать время работы каждого из вида сортировок для 100, 10000, 1000000
//    элементов.Заполнить таблицу.
// Дмитрий Волков


void separator() {
	printf("\n");
	for (int i = 0; i < 80; i++)
		printf("-");
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	return 0;
}

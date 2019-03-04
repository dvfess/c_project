#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <math.h>

#define _ separator();

void separator() {
	printf("\n");
	for (int i = 0; i < 80; i++) printf("-");
	printf("\n");
}

void dec2bin(int num) {
	//1. Реализовать  функцию  перевода  чисел  из  десятичной  системы  в  двоичную,  используя рекурсию.	// Дмитрий Волков
	if (num >= 2) {
		dec2bin(num / 2);
	}
	printf("%d", num % 2);
}


void PowFlat(int a, int b) {
	// 2. Реализовать функцию возведения числа a в степень b :
	//	  a.Без рекурсии.
	// Дмитрий Волков
	long res = 1;
	if (a == b && a == 0) {
		printf("NotDefined\n");
		return;
	}
	while (b) {
		res = res * a;
		b = b - 1;
	}
	printf("%d\n", res);
}


int PowRec(int a, int b) {
	// 2. Реализовать функцию возведения числа a в степень b :
	//    b.Рекурсивно.
	// Дмитрий Волков
	if (a == b && a == 0) return 0;
	if (b == 0)	return 1;
	int res = PowRec(a, b / 2);
	if (b % 2 == 0) return res * res;
	else return a * res * res;
}

void sol1() {
	// Задача 1.
	dec2bin(13);
}


void sol2() {
	// Задача 2.
	for (int i = 0; i < 13; i++)
		PowFlat(2, i);
	_
	for (int i = 0; i < 13; i++)
		printf("%d\n", PowRec(2, i));
}


int main() {
	sol1();
	_
	sol2();
	getchar();
}
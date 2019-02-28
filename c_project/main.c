#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <math.h>

#define _ separator();

typedef struct Point Point;

struct Point
{
	int x;
	int y;
};

void separator() {
	for (int i = 0; i < 79; i++) printf("-");
	printf("\n");
}
void humanWeight() {
	// 1. Вычислить индекс массы тела.
	double m, h;
	double BMI;
	printf("Введите рост человека: ");
	scanf_s("%lf", &h);
	printf("Введите массу: ");
	scanf_s("%lf", &m);
	BMI = m / (h * h);
	printf("Индекс массы тела: %f\n", BMI);
}

void max4() {
	// 2. Найти максимальное из четырёх чисел. Массивы не использовать.
	int max = INT_MIN, p;
	int i = 4;
	while (i > 0) {
		i--;
		printf("Введите целое число: ");
		scanf_s("%d", &p);
		if (p > max) max = p;
	}
	printf("Максимальное число: %d", max);
}

void exchange() {

	/*
	3. Написать программу обмена значениями двух целочисленных переменных: 
		a. С использованием третьей переменной.
		b. *Без использования третьей переменной.*/	int a = 1;
	int b = 2;
	int c = 3;
	printf("a=%d b=%d c=%d\n", a, b, c);
	printf("Обмен значений с использованием третьей переменной:\n");
	c = a;
	a = b;
	b = c;
	printf("a=%d b=%d c=%d\n", a, b, c);
	printf("Обмен значений с использованием xor:\n");
	a = 1;
	b = 2;
	c = 3;
	printf("a=%d b=%d c=%d\n", a, b, c);
	a ^= b;
	b ^= a;
	a ^= b;
	printf("a=%d b=%d c=%d\n", a, b, c);
}

void disc() {

	/*4. Написать программу нахождения корней заданного квадратного уравнения.*/	double a, b, c, d;
	printf("Введите значение а: ");
	scanf_s("%lf", &a);
	printf("Введите значение b: ");
	scanf_s("%lf", &b);
	printf("Введите значение c: ");
	scanf_s("%lf", &c);

	if ((b*b - 4 * a*c) >= 0)
	{
		d = (-1 * b + sqrt(b*b - 4 * a*c)) / (2 * a);
		printf("Первый корень равен %f\n", d);
		d = (-1 * b - sqrt(b*b - 4 * a*c)) / (2 * a);
		printf("Второй корень равен %f\n", d);
	}
	else {
		printf("Корни не вещественные. Дискриминант < 0.");
	}
}


void seasons() {
	int m;
	printf("Введите номер месяца: ");
	scanf_s("%d", &m);
	switch (m)
	{
	case 12:
	case 1:
	case 2:
		printf("Зима\n");
		break;
	case 3:
	case 4:
	case 5:
		printf("Весна\n");
		break;
	case 6:
	case 7:
	case 8:
		printf("Лето\n");
		break;
	case 9:
	case 10:
	case 11:
		printf("Осень\n");
		break;
	default:
		break;
	}
}

void years() {
	
	/*6. Ввести возраст человека(от 1 до 150 лет) и вывести его вместе со словом «год», «года» или «лет».*/

	//лет 0, 5-20, 105-120
	//1 - Год
	//2-4 - Года
	//5-9 - Лет

	for (int i = 0; i <= 150; i++)
	{
		printf("%3d ", i);
		switch (i % 10)
		{
		case 1:
			(i%100 % 11 == 0) ? printf("лет\n") : printf("год\n");
			break;
		case 2:
		case 3:
		case 4:
			(i %100 > 5 && i%100 < 20) ? printf("лет\n"): printf("года\n");
			break;
		case 0:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			printf("лет\n");
			break;
		default:
			(i < 21) ? printf("лет\n") : printf("год\n");
			break;
		}
	}
}

Point pInput(char txt) {
	Point a;
	const int B_SIZE = 8;
	while (1) {
		printf("Введите координату x, точки %c: ", txt);
		scanf_s("%d", &a.x);
		printf("Введите координату y, точки %c: ", txt);
		scanf_s("%d", &a.y);
		if ((a.y > 0 && a.y <= B_SIZE) && (a.x > 0 && a.x <= B_SIZE)){
			break;
		}
		else {
			printf("Размер доски - %d x %d клеток. Уточните координаты.\n", B_SIZE, B_SIZE);
		}

	}
	return a;
}

void pOut(Point x) {
	printf("x:%d y:%d\n", x.x, x.y);
}

void chess() {
	/*7.  С  клавиатуры  вводятся  числовые  координаты  двух  полей  шахматной  доски(x1, y1, x2, y2).
		Требуется определить, относятся ли к поля к одному цвету или нет.*/
	Point a, b;
	a = pInput('А');
	pOut(a);
	b = pInput('Б');
	pOut(b);

	if ((a.x + b.x) % 2 == (a.y-1 + b.y-1) % 2) {
		printf("Точки одного цвета.\n");
	} else {
		printf("Точки разного цвета.\n");
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	humanWeight();
	_
	max4();
	_
	exchange();
	disc();
	_
	seasons();
	_
	years();
	_
	chess();
	getchar();
	getchar();
	return 0;
}
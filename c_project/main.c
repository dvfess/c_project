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
	// 1. ��������� ������ ����� ����.
	double m, h;
	double BMI;
	printf("������� ���� ��������: ");
	scanf_s("%lf", &h);
	printf("������� �����: ");
	scanf_s("%lf", &m);
	BMI = m / (h * h);
	printf("������ ����� ����: %f\n", BMI);
}

void max4() {
	// 2. ����� ������������ �� ������ �����. ������� �� ������������.
	int max = INT_MIN, p;
	int i = 4;
	while (i > 0) {
		i--;
		printf("������� ����� �����: ");
		scanf_s("%d", &p);
		if (p > max) max = p;
	}
	printf("������������ �����: %d", max);
}

void exchange() {

	/*
	3. �������� ��������� ������ ���������� ���� ������������� ����������: 
		a. � �������������� ������� ����������.
		b. *��� ������������� ������� ����������.*/	int a = 1;
	int b = 2;
	int c = 3;
	printf("a=%d b=%d c=%d\n", a, b, c);
	printf("����� �������� � �������������� ������� ����������:\n");
	c = a;
	a = b;
	b = c;
	printf("a=%d b=%d c=%d\n", a, b, c);
	printf("����� �������� � �������������� xor:\n");
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

	/*4. �������� ��������� ���������� ������ ��������� ����������� ���������.*/	double a, b, c, d;
	printf("������� �������� �: ");
	scanf_s("%lf", &a);
	printf("������� �������� b: ");
	scanf_s("%lf", &b);
	printf("������� �������� c: ");
	scanf_s("%lf", &c);

	if ((b*b - 4 * a*c) >= 0)
	{
		d = (-1 * b + sqrt(b*b - 4 * a*c)) / (2 * a);
		printf("������ ������ ����� %f\n", d);
		d = (-1 * b - sqrt(b*b - 4 * a*c)) / (2 * a);
		printf("������ ������ ����� %f\n", d);
	}
	else {
		printf("����� �� ������������. ������������ < 0.");
	}
}


void seasons() {
	int m;
	printf("������� ����� ������: ");
	scanf_s("%d", &m);
	switch (m)
	{
	case 12:
	case 1:
	case 2:
		printf("����\n");
		break;
	case 3:
	case 4:
	case 5:
		printf("�����\n");
		break;
	case 6:
	case 7:
	case 8:
		printf("����\n");
		break;
	case 9:
	case 10:
	case 11:
		printf("�����\n");
		break;
	default:
		break;
	}
}

void years() {
	
	/*6. ������ ������� ��������(�� 1 �� 150 ���) � ������� ��� ������ �� ������ ����, ����� ��� ����.*/

	//��� 0, 5-20, 105-120
	//1 - ���
	//2-4 - ����
	//5-9 - ���

	for (int i = 0; i <= 150; i++)
	{
		printf("%3d ", i);
		switch (i % 10)
		{
		case 1:
			(i%100 % 11 == 0) ? printf("���\n") : printf("���\n");
			break;
		case 2:
		case 3:
		case 4:
			(i %100 > 5 && i%100 < 20) ? printf("���\n"): printf("����\n");
			break;
		case 0:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			printf("���\n");
			break;
		default:
			(i < 21) ? printf("���\n") : printf("���\n");
			break;
		}
	}
}

Point pInput(char txt) {
	Point a;
	const int B_SIZE = 8;
	while (1) {
		printf("������� ���������� x, ����� %c: ", txt);
		scanf_s("%d", &a.x);
		printf("������� ���������� y, ����� %c: ", txt);
		scanf_s("%d", &a.y);
		if ((a.y > 0 && a.y <= B_SIZE) && (a.x > 0 && a.x <= B_SIZE)){
			break;
		}
		else {
			printf("������ ����� - %d x %d ������. �������� ����������.\n", B_SIZE, B_SIZE);
		}

	}
	return a;
}

void pOut(Point x) {
	printf("x:%d y:%d\n", x.x, x.y);
}

void chess() {
	/*7.  �  ����������  ��������  ��������  ����������  ����  �����  ���������  �����(x1, y1, x2, y2).
		��������� ����������, ��������� �� � ���� � ������ ����� ��� ���.*/
	Point a, b;
	a = pInput('�');
	pOut(a);
	b = pInput('�');
	pOut(b);

	if ((a.x + b.x) % 2 == (a.y-1 + b.y-1) % 2) {
		printf("����� ������ �����.\n");
	} else {
		printf("����� ������� �����.\n");
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
//3. ***Требуется обойти конём шахматную доску размером N Ч M, пройдя через все поля доски
//по одному разу.Здесь алгоритм решения такой же, как и в задаче о 8 ферзях.Разница только в
//проверке положения коня.
// Дмитрий Волков


#include <locale.h>
#include <stdio.h>
#include <string.h>

#define MOVES 8 // Количество возможных ходов коня
#define DSIZE 50 // Максимальный размер доски

// Ходы коня
int steps[MOVES][2];
int horse_moves[][2] = {
 {-1, -2}, {-2, -1}, {-2,  1}, { 1, -2}, {-1,  2}, { 2, -1}, { 1,  2}, { 2,  1}
};


int N, M; // Размер доски
int move = 0; // Номер шага
int max_moves; // Количество ходов на всей доске
int result[DSIZE][DSIZE]; // Результат
int start_n, start_m; // Начальная клетка
int cur_n, cur_m; // Текущая клетка

// Проверка хода
int chkMove(int n, int m)
{
	// Координаты принадлежат доске и клетка == 0
	return result[n][m] == 0 && n > 0 && m > 0 && n <= N && m <= M;
}

int findPath(int cur_n, int cur_m, int cur_move)
{
	move = result[cur_n][cur_m] = cur_move; // Запомнить ход
	if (cur_move > max_moves) return 1; // Закончили обход

	for (int i = 0; i < MOVES; i++)
	{
		// Следующий возможный шаг
		int new_n = cur_n + steps[i][0];
		int new_m = cur_m + steps[i][1];

		if (chkMove(new_n, new_m) && findPath(new_n, new_m, move + 1)) {
			return 1;
		}
	}

	// Неудачный ход, отмена шага
	result[cur_n][cur_m] = 0;
	move--;
	return 0;
}

void print()
{
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
			printf("[ %2d ] ", result[j][i]);
		printf("\n\n");
	}
}

void searchSolution()
{
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			memset(result, 0, sizeof(result)); // Обнулить массив
			move = 0;
			start_n = cur_n = j;
			start_m = cur_m = i;
			result[cur_n][cur_m] = 1;
			max_moves = N * M - 1;
			findPath(start_n, start_m, 1);
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	N = 5; M = 5;
	// Заполняем шаги коня на все клетки новой доски
	memcpy(steps, horse_moves, sizeof(horse_moves));
	// Добавить Вансдорфа http://algolist.manual.ru/maths/combinat/knight.php
	searchSolution();
	print();

	return 0;
}

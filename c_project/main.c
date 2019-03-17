//3. ***Требуется обойти конём шахматную доску размером N Ч M, пройдя через все поля доски
//по одному разу.Здесь алгоритм решения такой же, как и в задаче о 8 ферзях.Разница только в
//проверке положения коня.
// Дмитрий Волков


#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define T char
#define _ separator();

typedef enum { false=0, true=1 } bool;

void separator() {
	printf("\n");
	for (int i = 0; i < 80; i++)
		printf("-");
	printf("\n");
}

// Опишем структуру узла списка
struct TNode
{
	T value;
	struct TNode *next;
};
typedef struct TNode Node;

struct TStack
{
	Node *head;
	int size;
	int maxSize;
};
typedef struct TStack Stack;
Stack opened;
Stack closed;
Stack stack;

int push(Stack *stk, T value)
{
	// Error codes:
	// 0 - No errors
	// 1 - Expire stack size
	// 2 - Can't allocate memory

	// Превышение ограничения на размер стэка
	if (stk->size >= stk->maxSize) return 1;

	//2.Добавить в программу «Реализация стека на основе односвязного списка»
	// проверку на выделение памяти. Если память не выделяется, то должно
	// выводиться соответствующее сообщение. Постарайтесь создать ситуацию,
	// когда память не будет выделяться(добавлением большого количества данных)
	// Дмитрий Волков

	Node *tmp;
	if ((tmp = (Node*)malloc(sizeof(Node))) != 0) {
		tmp->value = value;
		tmp->next = stk->head;
		stk->head = tmp;
		stk->size++;
	} else
		// Insufficient memory available
		return 2;
	return 0;
}

T pop(Stack *stk) {
	// Стэк пуст
	if (stk->size == 0) return '\0';
	// Временный указатель
	Node* next = NULL;
	// Значение «наверху» списка
	T value;
	value = stk->head->value;
	next = stk->head;
	stk->head = stk->head->next;
	// Запись, на которую указывала «голова», удаляем, освобождая память
	free(next);
	// Возвращаем значение, которое было в «голове»
	stk->size--;
	return value;
}

void PrintStack(Stack *stk)
{
	Node *current = stk->head;
	while (current != NULL)
	{
		printf("%c ", current->value);
		current = current->next;
	}
}


void sol1() {
	//2.Добавить в программу «Реализация стека на основе односвязного списка»
	// проверку на выделение памяти. Если память не выделяется, то должно
	// выводиться соответствующее сообщение. Постарайтесь создать ситуацию,
	// когда память не будет выделяться(добавлением большого количества данных)
	// Дмитрий Волков
	stack.maxSize = 100;
	stack.head = NULL;
	push(&stack, 'a');
	push(&stack, 'b');
	push(&stack, 'c');
	push(&stack, 'd');
	push(&stack, 'e');
	push(&stack, 'f');
	PrintStack(&stack);
}


bool brackets(char *str) {
	// Написать программу, которая определяет, является ли введённая скобочная
	// последовательность правильной.
	// Примеры правильных скобочных выражений
	// (), ([])(), {}(), ([{}]),
	// неправильных
	// )(, ())({ ), (, ]) }), ([(]),
	// для скобок [, (, { .
	// Например: (2 + (2 * 2)) или [2 / {5 * (4 + 7)}].
	const int s_size = 100;
	// выражение
	char *string = str;
	int length = 0;
	for (int i = 0; i < string[i] != '\0'; i++)
		length++;
	char paired = false;
	opened.maxSize = s_size;
	opened.head = NULL;

	for (int i = 0; i < length; i++)
	{
		if (string[i] == '[' || string[i] == '(' || string[i] == '{') {
			push(&opened, string[i]);
		}
		else if (string[i] == ']' || string[i] == ')' || string[i] == '}') {
			char open_pair = pop(&opened);
			if (open_pair == '\0') {
				return false;
			}
			switch (string[i])
			{
			case ']':
				if (open_pair == '[') paired = true;
				break;
			case ')':
				if (open_pair == '(') paired = true;
				break;
			case '}':
				if (open_pair == '{') paired = true;
				break;
			default:
				break;
			}
			if (!paired) {
				return false;
			}
		}
	}
	return paired;
}


void sol2() {
	char *expression[] =
	{
		"(2 + (2 * 2))",
		"[2 / {5 * (4 + 7)}]",
		"[2 / 6 { * () }]  ",
		"( ) ]"
	};

	for (int i = 0; i < 4; i++)
	{
		if (brackets(expression[i]) == 1)
			printf("В выражении '%s', указано верное количество скобок.\n", expression[i]);
		else
			printf("В выражении '%s', указано не верное количество скобок.\n", expression[i]);
	}
}


void sol3(){}


int main()
{
	setlocale(LC_ALL, "Rus");
	sol1();
	_
	sol2();
	_
	sol3();
	return 0;
}

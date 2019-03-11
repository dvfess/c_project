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

typedef enum { false, true } bool;

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

void push(Stack *stk, T value)
{
	if (stk->size >= stk->maxSize) {
		printf("Error stack size");
		return;
	}

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
	} else {
		printf("Insufficient memory available\n");
	}
}

T pop(Stack *stk) {
	if (stk->size == 0)
	{
		printf("Stack is empty");
		return '\0';
	}
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


void sol2() {
	// Написать программу, которая определяет, является ли введённая скобочная
	// последовательность правильной.
	// Примеры правильных скобочных выражений
	// (), ([])(), {}(), ([{}]),
	// неправильных
	// )(, ())({ ), (, ]) }), ([(]),
	// для скобок [, (, { .
	// Например: (2 + (2 * 2)) или [2 / {5 * (4 + 7)}].
	// выражение:
	const int s_size = 100;
	char *string = "(2 + (2 * 2))";
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
			char pair = pop(&opened);
			switch (string[i])
			{
			case ']':
				if (pair == '[') paired = true;
				break;
			case ')':
				if (pair == '(') paired = true;
				break;
			case '}':
				if (pair == '{') paired = true;
				break;
			default:
				break;
			}
			if (!paired) printf("Не все скобки парные! '%с' '%с'\n", string[i], pair);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	sol1();
	_
	sol2();
	return 0;
}

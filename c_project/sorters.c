
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int bubbleSort(int len, int *a) {
	int counter = 0;

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len - 1; j++) {
			counter++; // Сравнение в if
			if (a[j] > a[j + 1]) {
				counter++; // Свап
				swap(&a[j], &a[j + 1]);
			}
		}

	return counter;
}

int shakeIt(int len, int *arr) {
	// Шейкерная сортировка
	int counter = 0;
	int start = 0;
	int stop = len - 1;
	int incr = 1;
	
	while (start <= stop) {
		counter++;
		for (int i = start; i < stop; i++) {
			if (arr[i] > arr[i + 1]) swap(&arr[i], &arr[i + 1]);
			counter++;
		}
		stop--;

		for (int i = stop; i > start; i--) {
			if (arr[i] < arr[i - 1]) swap(&arr[i], &arr[i - 1]);
			counter++;
		}
		start++;
	}

	return counter;
}

int optBubbleSort(int len, int *a) {
	int counter = 0;
	int swapped;

	for (int i = 0; i < len; i++) {
		swapped = 0;
		for (int j = 0; j < len - 1; j++) {
			counter++; // Сравнение if
			if (a[j] > a[j + 1])
			{
				counter++;
				swapped++;
				swap(&a[j], &a[j + 1]);
			}
		}
		if (!swapped) break;
	}
	return counter;
}
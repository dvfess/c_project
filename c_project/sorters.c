
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
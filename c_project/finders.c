int binary(int element, int arrLen, int *arr) {
	/*3. ����������� �������� �������� ������ � ���� �������, ������� ��������� ���������������
		������. ������� ���������� ������ ���������� �������� ��� �1, ���� ������� �� ������.*/	int a = 0;	int b = arrLen;	int idx = (a + b) / 2;

	while (1) {
		if (arr[idx] == element) return idx;

		if (arr[idx] > element) {
			b = idx;
		}
		else if (arr[idx] < element) {
			a = idx;
		}

		idx = (a + b) / 2;

		if (a == b) return -1;
	}
	return -1;
}
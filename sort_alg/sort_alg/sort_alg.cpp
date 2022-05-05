#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define max 1050000
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
int list[max];

	void selection_sort(int list[], int n) { //���� ����
		int k = (int)(pow(2.0, (float)n));
		int i, j, least, temp;
		for (i = 0; i < k - 1; i++) {
			least = i;
			for (j = i + 1; j < k; j++) 
				if (list[j] < list[least]) least = j;
			SWAP(list[i], list[least], temp);
		}
	}
	void insertion_sort(int list[], int n) { //���� ����
		int k = (int)(pow(2.0, (float)n));
		int i, j, key;
		for (i = 1; i < k; i++) {
			key = list[i];
			for (j = i - 1; j >= 0 && list[j] > key; j--) {
				list[j + 1] = list[j];
			}
			list[j + 1] = key;
		}
	}
	void bubble_sort(int list[], int n) { //���� ����
		int k = (int)(pow(2.0, (float)n));
		int i, j, temp;
		for (i = k - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (list[j] > list[j + 1]) {
					SWAP(list[j], list[j + 1], temp);
				}
			}
		}
	}

	int partition(int list[], int left, int right) {
		int pivot, temp;
		int low, high;
		low = left;
		high = right + 1;
		pivot = list[left];

		do {
			do
				low++;
			while (list[low] < pivot);
			do
				high--;
			while (list[high] > pivot);
			if (low < high) SWAP(list[low], list[high], temp);
		} while (low < high);
		SWAP(list[left], list[high], temp);
		return high;
	}
	void quick_sort(int list[], int left, int right) { //�� ����
		if (left < right) {
			int q = partition(list, left, right);
			quick_sort(list, left, q - 1);
			quick_sort(list, q + 1, right);
		}
	}





	void make_rand(int list[], int n) { //�������� �Է�
		int k = (int)(pow(2.0, (float)n));
		srand((unsigned)time(NULL));
		for (int i = 0; i < k; i++)
			list[i] = 1 + rand() % k;
	}

	void make_worst(int list[], int n) { //�������� �Է�
		int j = 0;
		int k = (int)(pow(2.0, (float)n));
		for (int i = k; i > 0; i--) {
			list[j] = i;
			j++;
		}
			

	}

	void make_best(int list[], int n) { //������� �Է�
		int k = (int)(pow(2.0, (float)n));
		for (int i = 0; i < k; i++)
			list[i] = i;
	}


	int main(void) {
		float gap;
		time_t startTime = 0, endTime = 0;


		for (int i = 5; i < 21; i++) {
			make_best(list, i);
			int k = (int)(pow(2.0, (float)i));
			startTime = clock();
			bubble_sort(list, i);
			endTime = clock();
			gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
			printf("2�� %d�ŵ����� ���� �ð�: %f ��\n", i, gap);
		}

		return 0;
	}




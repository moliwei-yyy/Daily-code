#include<stdio.h>



void bubble(int array[], int n) {

	int i = 0;
	int p;
	for (i = 0; i < n - 1; i++) {
		if (array[i] > array[i + 1]) {
			p = array[i];
			array[i] = array[i + 1];
			array[i + 1] = p;
		}
	}
}
void BubbleSort(int array[], int n) {
	int i = 0;
	for (i = n; i > 0; i--) {
		bubble(array, i);
	}
}

int main() {
	int array[] = { 6,4,8,3,9,1,0,5,3,10 };
	int i = 0;
	
	BubbleSort(array, 10);
	
	
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
}

#include <stdio.h>

void swap(int *n1, int *n2){
	int temp = *n1;

	*n1 = *n2;
	*n2 = temp;
}

void printArray(int *array, int size){
	int i;
	for (i=0;i<size;i++){
		printf("%d\n", array[i]);
	}
	puts("**-**");
}

void bubble_sort(int *array, int size){
	int i,j;
	for (i=0;i<size-1;i++){
		for (j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

int main(void){

	int arr[5] = {10,5,15,3,7};
	printArray(arr, 5);
	bubble_sort(arr, 5);
	printArray(arr, 5);

	return 0;
}


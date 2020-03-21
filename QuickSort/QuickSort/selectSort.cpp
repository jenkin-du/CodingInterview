#include "selectSort.h"

void selectSort(int arr[], int length) {

	int min_index;
	for (int i = 0; i < length - 1; i++) {

		min_index = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
		}

		if (min_index != i) {
			int temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
		}
	}
}
#include "quickSort.h"

int getIndex(int arr[], int low, int high) {

	int key = arr[low];
	while (low < high) {

		while (low < high&&arr[high] >= key) {
			high--;
		}
		if (low < high) {
			arr[low] = arr[high];
		}

		while (low < high&&arr[low] <= key) {
			low++;
		}
		if (low < high) {
			arr[high] = arr[low];
		}
	}

	arr[low] = key;
	return low;
}

void quickSort(int arr[], int low, int high) {

	if (low < high) {

		int index = getIndex(arr, low, high);

		quickSort(arr, low, index - 1);
		quickSort(arr, index + 1, high);
	}
}
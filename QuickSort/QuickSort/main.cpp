#include <stdio.h>
#include "quickSort.h"
#include "selectSort.h"
#include "sortAge.h"


int main() {

	int arr[] = { 67,45,23,56,78,34,90,45 };
	//ð������
	//selectSort(arr, 8);
	//��������
	//quickSort(arr, 0, 7);

	//�������������
	sortAge(arr, 8);

	for (int i = 0; i < 8; i++) {
		printf("%d,", arr[i]);
	}
	printf("\n");
	return 0;
}


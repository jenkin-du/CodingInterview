#include <stdio.h>
#include "quickSort.h"
#include "selectSort.h"
#include "sortAge.h"


int main() {

	int arr[] = { 67,45,23,56,78,34,90,45 };
	//冒泡排序
	//selectSort(arr, 8);
	//快速排序
	//quickSort(arr, 0, 7);

	//对年龄进行排序
	sortAge(arr, 8);

	for (int i = 0; i < 8; i++) {
		printf("%d,", arr[i]);
	}
	printf("\n");
	return 0;
}


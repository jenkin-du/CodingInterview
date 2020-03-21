#include<stdio.h>
#include "quickSort.h"
#include "selectSort.h"


int main() {

	int arr[] = { 67,45,23,56,78,34,90,45 };
	//ц╟ещеепР
	selectSort(arr, 8);
	//©ЛкыеепР
	//quickSort(arr, 0, 7);

	for (int i = 0; i < 8; i++) {
		printf("%d,", arr[i]);
	}
	printf("\n");
	return 0;
}


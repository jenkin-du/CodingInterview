#include "sortAge.h"


void sortAge(int ages[], int length) {

	if (ages == nullptr || length <= 0) return;

	const int oldAge = 99;
	int counts[oldAge + 1];

	for (int i = 0; i < oldAge + 1; i++) {
		counts[i] = 0;
	}

	for (int i = 0; i < length; i++) {
		if (ages[i]<0 || ages[i]>oldAge) {
			printf("invalid age!\n");
			return;
		}
		counts[ages[i]]++;
	}

	int index = 0;
	for (int i = 0; i <= oldAge; i++) {
		for (int j = 0; j < counts[i]; j++) {
			ages[index] = i;
			index++;
		}
	}
}
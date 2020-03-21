#include<stdio.h>
#include<iostream>

using namespace std;

bool duplicate(int numbers[], int length, int* duplicate) {

	if (numbers == nullptr || length <= 0) {
		return false;
	}

	for (int i = 0; i < length; i++) {
		if (numbers[i]<0 || numbers[i]>length - 1) {
			return false;
		}
	}

	for (int i = 0; i < length; i++) {

		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				*duplicate = numbers[i];
				return true;
			}

			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;

			for (int j = 0; j < length; j++) {
				printf("%d", numbers[j]);
			}
			printf("\n");
		}
	}

	return false;

}



int main() {

	int numbers[] = { 2,3,0,5,4,6,6 };
	int du = -1;

	for (int j = 0; j < 7; j++) {
		printf("%d", numbers[j]);
	}
	printf("\n");

	bool h = duplicate(numbers, 7, &du);

	cout << "result: " << h << endl;
	cout << "duplicate:" << du << endl;

}
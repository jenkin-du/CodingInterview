#include<stdio.h>
#include<iostream>

using namespace std;

int replaceSpace(char arr[]);

int main() {

	char arr[100] = { " we  are family!" };
	replaceSpace(arr);

	cout << "result:" << arr << endl;
	return 0;
}

int replaceSpace(char arr[]) {

	if (arr == nullptr) {
		return -1;
	}

	int length = 0, count = 0;
	for (int i = 0; arr[i] != '\0'; i++) {
		length++;
		if (arr[i] == ' ') {
			count++;
		}
	}

	int newLength = length + 2 * count;
	char* p1 = arr + length;
	char* p2 = arr + newLength;
	while (p1 >= arr) {

		if (*p1 != ' ') {
			*p2-- = *p1--;
		}
		else {
			*p2-- = '0';
			*p2-- = '2';
			*p2-- = '%';

			p1--;
		}
	}

	return 0;
}
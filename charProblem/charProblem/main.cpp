#include<stdio.h>

char* fun(char arr[],int n);

int main() {

	char arr[] = "hellowold!";
	char* re = fun(arr, 6);
	for (int i = 0; *(re + i) != '\0'; i++) {
		printf("%c", *(re + i));
	}
	printf("\n");
	return 0;
}

char* fun(char arr[], int n) {
	return  arr + n - 1;
}
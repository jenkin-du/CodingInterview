#include<stdio.h>
#include<iostream>

using namespace std;

///在数组中找到重复的数字，不可以改变输入的数组，数组中的数字大小在1~length-1中
bool findDuplicate(int arr[], int length,int *duplicate) {

	if (arr == nullptr || length < 0) {
		return false;
	}

	int *tempArr = (int *)malloc(sizeof(int)*length);
	for (int i = 0; i < length; i++) {
		tempArr[i] = -1;
	}

	for (int i = 0; i < length; i++) {
		int number = arr[i];
		int temp = tempArr[number];
		if (temp == -1) {
			tempArr[number] = number;
		}else {
			*duplicate = number;
			return true;
		}
	}
	return false;
}

int main1() {

	int arr[] = {1,5,2,3,4,5,6,7};
	int duplicate = 0;
	bool result = findDuplicate(arr, 8, &duplicate);

	cout << "result:" << result << endl;
	cout << "duplicate:" << duplicate << endl;

	return 0;
}
#include<stdio.h>
#include<iostream>

using namespace std;

int countRange(int arr[], int length,int start,int end) {

	int count = 0;

	if (arr == nullptr || length < 0) {
		return count;
	}

	for (int i = 0; i < length; i++) {
		if (arr[i] >= start&&arr[i] <= end) {
			count++;
		}
	}

	return count;
}


///���������ҵ��ظ������֣������Ըı���������飬�����е����ִ�С��1~length-1��
bool findDuplicate2(int arr[], int length, int *duplicate) {

	if (arr == nullptr || length < 0) {
		return false;
	}

	
	int start = 1, end = length - 1;
	while (start <= end) {

		int middle = (end - start) / 2 + start;
		int count = countRange(arr, length, start, middle);
		if (start == end) {
			if (count > 1) {
				*duplicate = start;
				return true;
			}
			else {
				break;
			}
		}

		if (count > (middle - start + 1)) {
			end = middle;
		}
		else {
			start = middle + 1;
		}
		
	}

	return false;
}

//�ݹ�汾
bool findDupRecursive(int arr[], int length, int* duplicate,int start,int end) {

	int middle = (end - start) / 2 + start;
	int count = countRange(arr, length, start, middle);

	if (start == end) {
		if (count > 1) {
			*duplicate = start;
			return true;
		}else {
			return false;
		}
	}


	if (count > (middle - start + 1)) {
		findDupRecursive(arr, length, duplicate, start, middle);
	}else {
		findDupRecursive(arr, length, duplicate, middle + 1, end);
	}
}

int main() {

	int arr[] = { 4,4,5,4,3,2,6,7};
	int duplicate = 0;
	//bool result = findDuplicate2(arr, 8, &duplicate);
	bool result = findDupRecursive(arr, 8, &duplicate,1,7);

	cout << "result:" << result << endl;
	cout << "duplicate:" << duplicate << endl;

	return 0;
}
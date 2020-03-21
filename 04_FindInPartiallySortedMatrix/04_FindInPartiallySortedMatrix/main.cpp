#include<stdio.h>
#include<iostream>

using namespace std;

//在二维排序数组中找到某个数
bool findNumber(int arr[][4],int rows,int cols,int num);

int main() {

	int arr[4][4] = { { 1,2,8,9},
					 { 2,4,9,12},
					 {4,7,10,13},
					 {6,8,11,15} };

	int num = 5;
	bool isFind = findNumber(arr, 4, 4, num);
	cout << "result isFind:" << isFind<<endl;

	return 0;
}

bool findNumber(int arr[][4], int rows, int cols,int num) {

	if (arr == nullptr || rows <= 0 || cols <= 0) {
		return false;
	}

	bool isFind = false;
	int i = 0, j = cols - 1;
	while (i < rows&&j >= 0) {

		if (arr[i][j] == num) {
			isFind = true;
			break;
		}
		else if (arr[i][j] > num) {
			j--;
		}
		else {
			i++;
		}
	}
	return isFind;
}
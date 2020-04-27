#include <iostream>

using namespace std;

int minInRotateArr(int rotateArr[], int length);

int main() {

	int rotateArr[] = { 4,5,6,7,8,2,2,3 };
	int min = minInRotateArr(rotateArr, 8);
	cout << "min：" << min << endl;
	return 0;
}


int minInRotateArr(int rotateArr[], int length) {

	if (rotateArr == nullptr || length <= 0) {
		return -1;
	}

	int p1 = 0;//指向前一个子数列的指针
	int p2 = length - 1;//指向后一个子数列的指针
	int mid = p1;
	while (rotateArr[p1] >= rotateArr[p2]) {

		//结束条件：前一个子数列的指针和后一个子数列指针相邻，那么最小的值就位于后一个指针所指出
		if (p2 - p1 == 1) {
			return rotateArr[p2];
		}

		mid = (p1 + p2) / 2;
		//如果中间的值和两端一样，只能顺序查找
		if (rotateArr[p1] == rotateArr[p2] && rotateArr[p1] == rotateArr[mid]) {
			int min = rotateArr[p1];
			for (int i = p1 + 1; i <= p2; i++) {
				if (min > rotateArr[i]) min = rotateArr[i];
			}
			return min;
		}
		//如果中间的值比前一个指针指向的值大，说明mid所处前一个子数列
		if (rotateArr[mid] >= rotateArr[p1]) {
			p1 = mid;
		}
		//如果中间的值比后一个指针指向的值小，说明mid所处后一个子数列
		else if (rotateArr[mid] <= rotateArr[p2]) {
			p2 = mid;
		}
	}

	return rotateArr[mid];
}
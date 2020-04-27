#include <iostream>

using namespace std;

int minInRotateArr(int rotateArr[], int length);

int main() {

	int rotateArr[] = { 4,5,6,7,8,2,2,3 };
	int min = minInRotateArr(rotateArr, 8);
	cout << "min��" << min << endl;
	return 0;
}


int minInRotateArr(int rotateArr[], int length) {

	if (rotateArr == nullptr || length <= 0) {
		return -1;
	}

	int p1 = 0;//ָ��ǰһ�������е�ָ��
	int p2 = length - 1;//ָ���һ�������е�ָ��
	int mid = p1;
	while (rotateArr[p1] >= rotateArr[p2]) {

		//����������ǰһ�������е�ָ��ͺ�һ��������ָ�����ڣ���ô��С��ֵ��λ�ں�һ��ָ����ָ��
		if (p2 - p1 == 1) {
			return rotateArr[p2];
		}

		mid = (p1 + p2) / 2;
		//����м��ֵ������һ����ֻ��˳�����
		if (rotateArr[p1] == rotateArr[p2] && rotateArr[p1] == rotateArr[mid]) {
			int min = rotateArr[p1];
			for (int i = p1 + 1; i <= p2; i++) {
				if (min > rotateArr[i]) min = rotateArr[i];
			}
			return min;
		}
		//����м��ֵ��ǰһ��ָ��ָ���ֵ��˵��mid����ǰһ��������
		if (rotateArr[mid] >= rotateArr[p1]) {
			p1 = mid;
		}
		//����м��ֵ�Ⱥ�һ��ָ��ָ���ֵС��˵��mid������һ��������
		else if (rotateArr[mid] <= rotateArr[p2]) {
			p2 = mid;
		}
	}

	return rotateArr[mid];
}
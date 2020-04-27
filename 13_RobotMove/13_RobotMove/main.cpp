#include<iostream>

using namespace std;

//����������ߵĸ�����
int movingCount(int threshold, int rows, int cols);
//����������߸������ĺ��ĺ���
int movingCountCore(int threshold, int rows, int cols,int row,int col, bool* visited);
//����Ƿ������
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
//��������λ��֮��
int getDigitalSum(int number);

int main() {

	int count = movingCount(3, 5, 5);
	cout << "count:" << count << endl;

	return 0;
}

int movingCount(int threshold, int rows, int cols) {

	if (threshold < 0 || rows <= 0 || cols <= 0) {
		return 0;
	}

	bool* visited = new bool[rows*cols];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			visited[i*cols + j] = false;
		}
	}

	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

	delete[] visited;

	return count;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited) {

	int count = 0;
	if (check(threshold, rows, cols, row, col, visited)) {

		visited[row*cols + col] = true;
		count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row - 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col + 1, visited)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visited);
	}

	return count;
}

bool check(int threshold, int rows, int cols, int row, int col, bool *visited) {
	
	if (row >= 0 && row < rows&&col >= 0 && col < cols && !visited[row*cols + col]) {
		int sum = getDigitalSum(row) + getDigitalSum(col);
		if (sum <= threshold) {
			return true;
		}
	}
	return false;
}

int getDigitalSum(int number) {

	int sum = 0;
	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}

	return sum;
}
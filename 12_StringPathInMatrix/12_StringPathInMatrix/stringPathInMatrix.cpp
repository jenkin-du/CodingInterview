#include<iostream>

using namespace std;

bool hasPath(char* matrix, int rows,int cols,char* str);

bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int pathLength, bool* visited);


int main()
{
	char* matrix = "abtgcfcsjdeh";
	char* str = "bfce";
	bool isHasPath = hasPath(matrix, 3, 4, str);
	if (isHasPath) {
		cout << "has path" << endl;
	}
	else {
		cout << "has no path" << endl;
	}
	
    return 0;
}

bool hasPath(char* matrix, int rows, int cols, char* str) {

	if (matrix == nullptr || str == nullptr || rows < 1 || cols < 1) {
		return false;
	}

	bool* visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);
	int pathLength = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (hasPathCore(matrix, rows, cols, i, j, str, pathLength, visited)) {
				return true;
			}
		}
	}

	delete visited;
	return false;
}

bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int pathLength, bool* visited) {

	//匹配结束
	//提示，使用递归解决问题，必定先写结束条件
	if (str[pathLength] == '\0') {
		return true;
	}

	bool isHasPath = false;
	//判断当前字符
	if (row >= 0 && row < rows && cosl >= 0 && col < cols&&
		matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col]) {
		
		visited[row*cols + col] = true;
		pathLength++;

		//判断周围字符
		isHasPath = hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited);

		if (!isHasPath) {
			visited[row*cols + col] = false;
			pathLength--;
		}

	}
	return isHasPath;
}
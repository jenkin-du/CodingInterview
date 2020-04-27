#include<iostream>

using namespace std;

long long fib(int n);

int main() {

	long long r = fib(5000);
	cout << "result:" << r << endl;

	return 0;
}

long long fib(int n) {

	int result[2] = { 0,1 };
	if (n < 2) {
		return result[n];
	}
	long long fib0 = 0;
	long long fib1 = 1;
	long long fibN = 0;
	for (int i = 2; i <= n; i++) {
		fibN = fib0 + fib1;

		fib0 = fib1;
		fib1 = fibN;
	}

	return fibN;
}
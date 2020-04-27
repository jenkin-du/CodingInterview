#include <iostream>

using namespace std;

int main() {

	int n = 0, a = 0;
	cin >> n;
	while (n > 0) {
		int sum = 0;
		for (int i = 0; i<n; i++) {
			cin >> a;
			sum += a;
		}
		cout << sum ;
		cin >> n;
	}
	return 0;
}
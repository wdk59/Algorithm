#include <iostream>
using namespace std;

int main() {
	int total = 0, n = 0;

	cin >> total >> n;

	for (int i = 0; i < n; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		total -= a * b;
	}

	cout << (total == 0 ? "Yes" : "No");

	return 0;
}

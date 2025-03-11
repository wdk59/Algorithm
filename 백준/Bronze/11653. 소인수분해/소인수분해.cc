#include <iostream>
using namespace std;

int main() {
	int N = 0;

	cin >> N;

	int i = 2;
	while (N > 1) {
		if (N % i == 0) {
			cout << i << '\n';
			N /= i;
		}
		else { i++; }
	}

	return 0;
}

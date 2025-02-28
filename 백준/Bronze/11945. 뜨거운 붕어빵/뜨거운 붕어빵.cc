#include <iostream>
using namespace std;

int main() {
	int N = 0, M = 0;
	string shape[11];

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> shape[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = M - 1; j >= 0; j--) {
			cout << shape[i][j];
		}
		cout << '\n';
	}

	return 0;
}
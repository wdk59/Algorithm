#include <iostream>
using namespace std;

int main() {
	int matrix[100][100];

	int N = 0, M = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix[i][j];
		}
	}

	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			cout << matrix[i][j] + tmp << ' ';
		}
		cout << '\n';
	}

	return 0;
}

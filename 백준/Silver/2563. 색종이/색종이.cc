#include <iostream>
using namespace std;

int board[100][100] = { {0, }, };

int main() {
	int num = 0;
	cin >> num;

	for (int n = 0; n < num; n++) {
		int x = 0, y = 0;
		cin >> x >> y;
		for (int i = x - 1; i < x + 9; i++) {
			for (int j = y - 1; j < y + 9; j++) {
				board[j][i] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			if (board[i][j] == 1)
				cnt++;
	}

	cout << cnt;

	return 0;
}
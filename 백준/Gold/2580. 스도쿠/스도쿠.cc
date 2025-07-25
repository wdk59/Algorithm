#include <iostream>

using namespace std;

int arr[9][9];
bool isFound = false;

int check(int x, int y, int n) {
	// 같은 행 또는 열에 중복되는 수가 있는지 확인
	for (int i = 0; i < 9; i++)
		if (arr[x][i] == n || arr[i][y] == n)
			return false;

	// 3x3 정사각형 안에 중복되는 수가 있는지 확인
	int nx = x / 3 * 3;
	int ny = y / 3 * 3;
	for (int i = nx; i < nx + 3; i++)
		for (int j = ny; j < ny + 3; j++)
			if (n == arr[i][j])
				return false;
	return true;
}

void dfs(int x, int y) {
	if (isFound)
		return;

	if (y == 9) {
		x++;
		y = 0;
	}

	if (x == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << arr[i][j] << ' ';
			cout << '\n';
		}
		isFound = true;

		return;
	}

	if (arr[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (check(x, y, i)) {
				arr[x][y] = i;
				dfs(x, y + 1);
				arr[x][y] = 0;
			}
		}
	}
	else dfs(x, y + 1);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];

	dfs(0, 0);
	return 0;
}
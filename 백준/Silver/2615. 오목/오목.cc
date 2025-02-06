#include <iostream>
using namespace std;

int board[19][19];

bool right(int x, int y) {
	bool result = false;

	if (x < 19) {
		if (y <= 14) {
			int cnt = 1;

			// 5연속 확인
			for (int i = 1; i < 5; i++) {
				if (board[x][y] == board[x][y + i])
					cnt++;
			}
			
			if (cnt == 5)
				result = true;

			/* 6번째 확인 */
			// 5연속인 상태에서 -1번째 또는 6번째도 같은 색이면 실패
			if (result) {
				if (y > 0 && board[x][y] == board[x][y - 1]) {
					result = false;
				}
				if (y <= 13 && board[x][y] == board[x][y + 5])
					result = false;
			}
		}
		
	}

	return result;
}

bool down(int x, int y) {
	bool result = false;
	
	if (y < 19) {
		if (x <= 14) {
			int cnt = 1;

			// 5연속 확인
			for (int i = 1; i < 5; i++) {
				if (board[x][y] == board[x + i][y])
					cnt++;
			}

			if (cnt == 5)
				result = true;

			/* 6번째 확인 */
			// 5연속인 상태에서 -1번째 또는 6번째도 같은 색이면 실패
			if (result) {
				if (x > 0 && board[x][y] == board[x - 1][y])
					result = false;
				if (x <= 13 && board[x][y] == board[x + 5][y])
					result = false;
			}
		}
	}

	return result;
}

bool rightDown(int x, int y) {
	bool result = false;

	if (x <= 14 && y <= 14) {
		int cnt = 1;

		// 5연속 확인
		for (int i = 1; i < 5; i++) {
			if (board[x][y] == board[x + i][y + i])
				cnt++;
		}

		if (cnt == 5)
			result = true;

		/* 6번째 확인 */
		// 5연속인 상태에서 -1번째 또는 6번째도 같은 색이면 실패
		if (result) {
			if (x > 0 && y > 0 && board[x][y] == board[x - 1][y - 1])
				result = false;
			if (x <= 13 && y <= 13 && board[x][y] == board[x + 5][y + 5])
				result = false;
		}
	}

	return result;
}

bool rightUp(int x, int y) {
	bool result = false;

	if (x >= 4 && x < 19 && y <= 14) {
		int cnt = 1;

		// 5연속 확인
		for (int i = 1; i < 5; i++) {
			if (board[x][y] == board[x - i][y + i])
				cnt++;
		}

		if (cnt == 5)
			result = true;

		/* 6번째 확인 */
		// 5연속인 상태에서 -1번째 또는 6번째도 같은 색이면 실패
		if (result) {
			if (x < 18 && y > 0 && board[x][y] == board[x + 1][y - 1])
				result = false;
			if (x >= 5 && y <= 13 && board[x][y] == board[x - 5][y + 5])
				result = false;
		}
	}

	return result;
}

int main() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> board[i][j];
		}
	}

	bool stop = false;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			/* 바둑알 발견 시 승리 조건 확인 */
			if (board[i][j] != 0) {
				/* 승리자 발견 시 결과 출력 */
				if (right(i, j) || down(i, j) || rightDown(i, j) || rightUp(i, j)) {
					cout << board[i][j] << "\n";
					cout << i + 1 << " " << j + 1;
					stop = true;
					break;
				}
			}
		}
		if (stop)
			break;
	}

	if (!stop)
		cout << 0;

	return 0;
}

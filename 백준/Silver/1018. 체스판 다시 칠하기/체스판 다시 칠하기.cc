#include <iostream>
using namespace std;

int main() {
	char board[51][51];
	int N = 0, M = 0;
	cin >> N >> M;

	// 보드판 입력
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	/* 다시 칠할 칸 수의 최소값 찾기 */int result = N * M;
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int try1 = 0, try2 = 0;	// 1: 시작점 색 변화X   2: 시작점 색 바꿈
			for (int column = 0; column < 8; column++) {
				for (int row = 0; row < 8; row++) {
					// 시작점과 색이 같아야 하는 곳
					if ((i + column + j + row) % 2 == 0) {
						// 시작점 색을 바꾸지 않는 경우
						if (board[i][j] != board[i + column][j + row]) {
							try1++;
						}
						// 시작점 색을 바꾸는 경우
						if (board[i][j] == board[i + column][j + row]) {
							try2++;
						}
					}
					// 시작점과 색이 달라야 하는 곳
					else {
						// 시작점 색을 바꾸는 경우
						if (board[i][j] == board[i + column][j + row]) {
							try1++;
						}
						// 시작점 색을 바꾸는 경우
						if (board[i][j] != board[i + column][j + row]) {
							try2++;
						}
					}
				}
			}
			result = min(result, min(try1, try2));
		}
	}

	cout << result;

	return 0;
}

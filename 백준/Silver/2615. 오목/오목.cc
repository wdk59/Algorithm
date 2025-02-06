#include <iostream>
using namespace std;

int board[19][19];

int search(int x, int y, int dx, int dy, int* minX, int* minY, int cnt) {
	// 바둑알을 5개 이상 찾았을 때는 더 탐색하는 의미가 없음
	if (cnt > 5) {
		return 20;
	}

	// 가려는 바둑알 위치 설정
	int nx = x + dx;
	int ny = y + dy;

	// 가려는 바둑알이 판을 벗어나면 탐색 중지
	if (nx < 0 || nx > 18 || ny < 0 || ny > 18)
		return cnt;

	// 바둑알 색 비교
	if (board[x][y] == board[nx][ny]) {
		
		/* 현재 방향에서 조건에 맞는 가장 왼쪽 위 바둑알 좌표 저장 */
		// 항상 위에서부터 탐색하기 때문에 현재보다 위에서 오목인 경우는 없음
		if (ny < *minY) {
			*minX = nx;
			*minY = ny;
		}

		cnt = search(nx, ny, dx, dy, minX, minY, cnt + 1);
	}

	return cnt;
}

bool solution(int x, int y, int* ansX, int* ansY) {
	// 방향: 가로, 세로, 우하향, 우상향
	int dx[4] = {0, 1, 1, -1};
	int dy[4] = { 1, 0, 1, 1 };

	// 각 방향별로 연속으로 색이 같은 바둑알 수 세기
	for (int i = 0; i < 4; i++) {
		int cnt = 1;
		int minX = x, minY = y;

		//양방향으로 연산
		
		cnt += search(x, y, dx[i], dy[i], &minX, &minY, 0) + search(x, y, -dx[i], -dy[i], &minX, &minY, 0);

		if (cnt == 5) {
			*ansX = minX;
			*ansY = minY;

			return true;
		}
	}

	return false;
}





int main() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> board[i][j];
		}
	}

	int ansX = -2, ansY = -2;
	bool stop = false;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {

			/* 바둑알 발견 시 승리 조건 확인 */
			if (board[i][j] != 0) {

				/* 승리자 발견 시 결과 출력 */
				if (solution(i, j, &ansX, &ansY)) {
					cout << board[i][j] << "\n";
					cout << ansX + 1 << " " << ansY + 1;
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

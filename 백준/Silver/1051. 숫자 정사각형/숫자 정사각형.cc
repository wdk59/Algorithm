#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main() {
	/* 직사각형 입력 */

	int N = 0, M = 0;
	cin >> N >> M;
	
	int rectangle[51][51];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &rectangle[i][j]);
		}
	}

	/* 정사각형 모양 유지하며 직사각형 탐색 */
	int maxLen = min(N, M);	// 정사각형의 한 변의 길이가 될 수 있는 최대 길이
	int result = 0;
	for (int i = 0; i < maxLen; i++) {
		for (int row = 0; row < N - i; row++) {
			for (int column = 0; column < M - i; column++) {
				if (rectangle[row][column] == rectangle[row][column + i] && rectangle[row][column + i] == rectangle[row + i][column] && rectangle[row + i][column] == rectangle[row + i][column + i]) {
					result = max(result, i);
				}
			}
		}
	}

	cout << (result + 1) * (result + 1);

	return 0;
}

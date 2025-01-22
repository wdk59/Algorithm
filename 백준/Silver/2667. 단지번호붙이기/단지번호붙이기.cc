#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 0;
int** map;

int DFS(int row, int column, int cnt) {
	// 유효한 집이 없는 경우: 다음 집으로 바로 ㄱㄱ
	if (map[row][column] == 0)
		return 0;

	// 유효한 집이 있는 경우: 인접한 집 탐색
	cnt++;
	map[row][column] = 0;	// 방문한 집은 무시하도록 설정
	if (row > 0) {
		if (map[row - 1][column] == 1)
			cnt = DFS(row - 1, column, cnt);
	}
	if (row < N - 1) {
		if (map[row + 1][column] == 1)
			cnt = DFS(row + 1, column, cnt);
	}
	if (column > 0) {
		if (map[row][column - 1] == 1)
			cnt = DFS(row, column - 1, cnt);
	}
	if (column < N - 1) {
		if (map[row][column + 1] == 1)
			cnt = DFS(row, column + 1, cnt);
	}

	return cnt;
}

int main() {
	// 지도 크기 입력
	cin >> N;

	// 2차원 배열 map 동적 할당
	map = new int* [N];
	for (int i = 0; i < N; i++)
		map[i] = new int[N];
	// 지도 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);
	}

	// 탐색
	vector<int> houses;	// 우선순위 큐: 자동 정렬
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt = DFS(i, j, 0);
			if (cnt != 0) {
				houses.push_back(cnt);
				cnt = 0;
			}
		}
	}

	// 정렬
	sort(houses.begin(), houses.end());
	
	// 결과 출력
	cout << houses.size() << "\n";
	for (int i = 0; i < houses.size(); i++) {
		cout << houses[i] << "\n";
	}

	// 2차원 배열 map 반환
	for (int i = 0; i < N; i++)
		delete[] map[i];
	delete[] map;

	return 0;
}

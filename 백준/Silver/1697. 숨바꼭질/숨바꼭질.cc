#include <iostream>
#include <queue>
#include <utility>
using namespace std;

//int graph[100001][100001];	// 배열 너무 커서 사용 불가
bool visited[100001];

// 0~100,000 범위 안이면서 방문하지 않는 노드인지 검사
bool canVisit(int num) {
	if (num < 0 || num > 100000 || visited[num])
		return false;
	return true;
}

void BFS(int v, int goal) {
	queue<pair<int, int>> q;
	int floor = 0;
	
	// 시작값 설정
	q.push({v, floor});
	visited[v] = true;

	while (!q.empty()) {
		// 현재 방문 노드 검사
		v = q.front().first;
		floor = q.front().second;
		q.pop();

		if (v == goal) {
			cout << floor;
			break;
		}

		// 다음 층의 노드 만들기
		if (canVisit(v - 1)) {
			q.push({ v - 1, floor + 1 });
			visited[v - 1] = true;
		}
		if (canVisit(v + 1)) {
			q.push({ v + 1, floor + 1 });
			visited[v + 1] = true;
		}
		if (canVisit(v * 2)) {
			q.push({ v * 2, floor + 1 });
			visited[v * 2] = true;
		}
	}
}

int main() {
	int N = 0, K = 0;
	cin >> N >> K;

	BFS(N, K);

	return 0;
}

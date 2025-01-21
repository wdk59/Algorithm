#include <iostream>
#include <queue>
using namespace std;

int N = 0, M = 0, V = 0;
int edges[1001][1001];	// 간선
bool visited[1001];			// 노드 방문 여부

void DFS(int v) {
	// 노드 방문
	cout << v << " ";
	visited[v] = true;	// 방문: true
	// 방문한 노드와 연결된 노드 탐색
	for (int i = 1; i <= N; i++) {
		// 간선이 연결되어 있지 않거나 이미 방문한 노드는 건너뛰기
		if (edges[v][i] == 0 || visited[i])
			continue;

		DFS(i);
	}
}

void BFS(int v) {
	queue<int> q;	// 방문 큐
	// 시작 노드 방문
	q.push(v);
	visited[v] = false;	// 방문: false(DFS 반전)

	// 방문 노드와 연결된 노드들을 큐에 넣고, 순서대로 방문 반복
	while (!q.empty()) {
		// q 맨 앞 값을 시작값으로 설정
		v = q.front();
		cout << v << " ";
		q.pop();

		for (int i = 1; i <= N; i++) {
			// 간선이 연결되어 있지 않거나 이미 방문한 노드는 건너뛰기
			if (edges[v][i] == 0 || !visited[i])
				continue;

			q.push(i);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M >> V;

	// 간선 입력
	for (int i = 1; i <= M; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		// 간선 양방향 연결 (무방향)
		edges[a][b] = edges[b][a] = 1;
	}

	DFS(V);
	cout << "\n";
	BFS(V);

	return 0;
}

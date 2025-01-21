#include <iostream>
#include <queue>
using namespace std;

int n = 0, m = 0, v = 0;
int graph[1001][1001];	// 간선 저장. 초기화: 0
bool visited[1001];		// 방문했는가. 초기화: 0

void DFS(int v) {
	cout << v << " ";
	visited[v] = 1;	// 방문했으면 1
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1 || graph[v][i] == 0)
			continue;
		DFS(i);
	}
}

void BFS(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = 0;	// 방문했으면 0 (DFS에서 쓰던 거 초기화 안 해서 그냥 반전으로...)
	while (!q.empty()) {
		v = q.front();
		cout << q.front() << ' ';
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0 || graph[v][i] == 0)
				continue;
			q.push(i);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;	// 서로 연결되어 있음을 표시 (무방향)
	}

	DFS(v);
	cout << "\n";
	BFS(v);

	return 0;
}
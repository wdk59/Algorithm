#include <iostream>
#include <vector>
using namespace std;

// MAX: 800 * 800 * 1000
#define INF 160000001

int dijkstra(int& n, vector<vector<int>>& graph, int departure, int arrival) {
	vector<int> minCosts(n + 1, INF);	// 노드마다 최소 비용 저장
	vector<bool> visited(n + 1, false);
	minCosts[departure] = 0;
	for (int i = 0; i < n; i++) {
		int min = INF, closest = -1;
		for (int j = 1; j < n + 1; j++) {
			if (!visited[j] && minCosts[j] < min) {
				min = minCosts[j];
				closest = j;
			}
		}
		// 갈 수 있는 곳이 없으면 탐색 종료
		if (closest == -1)
			break;

		// 갈 수 있는 가장 가까운 곳 선택
		visited[closest] = true;

		for (int j = 1; j < n + 1; j++) {
			if (visited[j] || graph[closest][j] == INF)
				continue;

			int newDistance = minCosts[closest] + graph[closest][j];
			minCosts[j] = (minCosts[j] < newDistance ? minCosts[j] : newDistance);
		}
	}

	return minCosts[arrival];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	int N = 0, E = 0;
	cin >> N >> E;
	// 간선 입력 및 그래프 그리기
	vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	// 통과 지점 입력
	pair<int, int> point = { 0, 0 };
	cin >> point.first >> point.second;

	/* 다익스트라 */
	int answer = 0, tmp = 0;
	answer = dijkstra(N, graph, 1, point.first) + dijkstra(N, graph, point.first, point.second) + dijkstra(N, graph, point.second, N);
	tmp = dijkstra(N, graph, 1, point.second) + dijkstra(N, graph, point.second, point.first) + dijkstra(N, graph, point.first, N);
	answer = answer < tmp ? answer : tmp;
	cout << (answer >= INF ? -1 : answer);

    return 0;
}

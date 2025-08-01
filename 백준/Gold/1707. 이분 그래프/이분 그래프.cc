#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> graph;
	vector<int> group;	// 각 노드가 배정된 그룹 저장

	int K = 0;
	cin >> K;

	for (int testCase = 0; testCase < K; testCase++) {
		int V = 0, E = 0;
		cin >> V >> E;

		// 벡터 크기 지정
		graph = vector<vector<int>>(V + 1, vector<int>());
		group = vector<int>(V + 1, 0);

		// 간선 연결 (양방향)
		for (int i = 0; i < E; i++) {
			int a = 0, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		/* BFS: 각 정점의 그룹 배정 */
		// 여러 개의 컴포넌트를 가진 그래프일 수도 있기 때문에 모든 정점을 검사해야 한다.
		for (int i = 1; i <= V; i++) {
			// 이미 방문한 컴포넌트의 노드인 경우에는 건너뛰기
			if (group[i]) { continue; }

			queue<int> q;
			q.push(i);
			group[i] = 1;	// 루트 노드 그룹 배정

			// 루트가 아닌 노드들 그룹 배정
			while (!q.empty()) {
				int node = q.front();	// 현재 방문 중인 노드

				// 현재 노드와 인접한 노드들 검사
				for (int j = 0; j < graph[node].size(); j++) {
					// 그룹이 배정되지 않은 노드에 그룹 배정
					int next = graph[node][j];
					if (!group[next]) {
						q.push(next);
						// 다음 노드는 현재 노드의 그룹과 다른 그룹으로 배정
						group[next] = (group[node] == 1) ? 2 : 1;
					}
				}

				q.pop();
			}
		}

		/* 이분 그래프 조건 만족 검사 */
		bool result = true;

		// 모든 노드들이 각자 연결된 인접 노드들과 다른 그룹에 속하면 이분 그래프의 조건을 만족
		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				if (group[i] == group[graph[i][j]]) {
					result = false;
					break;
				}
			}
			if (!result)	break;
		}

		// 이분그래프 조건 만족 검사 결과 출력
		cout << (result ? "YES\n" : "NO\n");
	}
}

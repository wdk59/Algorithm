#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> group;

void DFS(int start) {
	if (!group[start])	// 방문 안 한 노드이면 임의로 그룹 지정 (루트 노드가 여기서 걸림)
		group[start] = 1;

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!group[next]) {
			if (group[start] == 1) { group[next] = 2; }
			else if (group[start] == 2) { group[next] = 1; }
			DFS(next);
		}
	}
}

bool isBipartite(int v) {
	for (int i = 1; i <= v; i++) {
		// 모든 노드가 각자 인접한 노드들과 다른 그룹이면 이분 그래프의 조건을 만족함
		for (int j = 0; j < graph[i].size(); j++) {
			// 현재 노드와 다음 노드의 그룹 확인
			if (group[i] == group[graph[i][j]]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int K = 0, V = 0, E = 0;
	cin >> K;

	// 정점 및 간선 정보 입력
	for (int i = 0; i < K; i++) {
		cin >> V >> E;
		// 벡터 크기 재설정
		graph = vector<vector<int>>(V + 1, vector<int>());
		group = vector<int>(V + 1, 0);
		for (int j = 0; j < E; j++) {
			int a = 0, b = 0;
			cin >> a >> b;
			graph[a].push_back(b);	// emplace_back()?
			graph[b].push_back(a);
		}

		// 그룹 지정
		for (int i = 1; i <= V; i++) {
			if (!group[i])	// 이미 그룹이 배정된 노드는 건너뛰기
				DFS(i);
		}

		// 이분 그래프인지 확인
		cout << (isBipartite(V) ? "YES\n" : "NO\n");
	}

	return 0;
}

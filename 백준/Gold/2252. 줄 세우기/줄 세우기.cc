#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> std_adj[32000];	// 앞에 와야 하는 수를 저장할 배열이 있어야 하므로 벡터 배열로 선언
vector<bool> isVisited;	// 각 노드를 방문했는지 확인. 방문했으면 front에 잇어도 출력 안 함.

void DFS(int node) {
	isVisited[node] = true;	// 출력할 때 해도 상관 없을듯

	// front 확인
	for (int i = 0; i < std_adj[node].size(); i++) {
		if (!isVisited[std_adj[node][i] - 1]) { DFS(std_adj[node][i] - 1); }
	}

	cout << node + 1 << " ";
}

int main() {
	int n = 0, m = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		isVisited.push_back(false);
	}

	// 서로 비교한 값을 받음
	int a = 0, b = 0;
	for (int i = 0; i < m; i++) {
		a = 0; b = 0;
		cin >> a >> b;
		std_adj[b - 1].push_back(a);
	}

	// std의 각 인덱스를 돌면서 front를 확인해서 먼저 와야 할 것 먼저 출력
	for (int i = 0; i < n; i++) {
		if (!isVisited[i]) { DFS(i); }
	}

	return 0;
}

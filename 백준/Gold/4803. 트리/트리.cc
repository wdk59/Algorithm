#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> near;
vector<bool> visited;

bool DFS(int node, int parent) {
	visited[node] = true;

	for (int i = 0; i < near[node].size(); i++) {
		if (!visited[near[node][i]]) {
			if (DFS(near[node][i], node))
				return true;	// 자식 사이클 누적
		}
		else if (near[node][i] != parent) {
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = -1, m = -1;
	int a = 0, b = 0;
	int caseNum = 0, answer = 0;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		near = vector<vector<int>>(n, vector<int>());
		visited = vector<bool>(n, false);
		answer = 0;

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			near[a - 1].push_back(b - 1);
			near[b - 1].push_back(a - 1);
		}
		for (int i = 0; i < n; i++)
			if (!visited[i] && !DFS(i, -1))
				answer++;

		cout << "Case " << ++caseNum << ": ";
		if (answer == 0)
			cout << "No trees.\n";
		else if (answer == 1)
			cout << "There is one tree.\n";
		else
			cout << "A forest of " << answer << " trees.\n";
	}

	return 0;
}

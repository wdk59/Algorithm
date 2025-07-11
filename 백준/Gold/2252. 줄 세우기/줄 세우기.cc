#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> front;
vector<bool> visited;

void DFS(int node) {
	visited[node] = true;

	for (int i = 0; i < front[node].size(); i++)
		if (!visited[front[node][i]])
			DFS(front[node][i]);

	cout << node + 1 << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;

	front = vector<vector<int>>(n, vector<int>());
	visited = vector<bool>(n, false);

	int a = 0, b = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		front[b - 1].push_back(a - 1);
	}
	
	for (int i = 0; i < n; i++)
		if (!visited[i])
			DFS(i);

	return 0;
}

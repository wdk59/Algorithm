#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<bool>& visited, vector<vector<int>>& computers, int& cnt, int now) {
	if (visited[now])
		return;

	visited[now] = true;
	cnt++;
	for (int i = 0; i < computers[now].size(); i++)
		dfs(visited, computers, cnt, computers[now][i]);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/* 입력 */
	int N = 0, M = 0;
	cin >> N >> M;
	vector<vector<int>> computers(N + 1, vector<int>());	// 1-based
	int tmp1 = 0, tmp2 = 0;
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		computers[tmp1].push_back(tmp2);
		computers[tmp2].push_back(tmp1);
	}

	/* 풀이 */
	vector<bool> visited(N, false);
	int cnt = 0;
	dfs(visited, computers, cnt, 1);

	/* 출력 */
	cout << cnt - 1;	// 자기자신(1번) 빼기

	return 0;
}

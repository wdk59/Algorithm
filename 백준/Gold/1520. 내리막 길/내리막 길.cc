#include <iostream>
#include <vector>
using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int DFS(int x, int y, int& M, int& N, vector<vector<int>>& dp, vector<vector<int>>& map) {
	if (x == M - 1 && y == N - 1)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < M && ny < N)
			if (map[nx][ny] < map[x][y])
				dp[x][y] = dp[x][y] + DFS(nx, ny, M,  N, dp, map);
	}

	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/* 입력 */
	int M = 0, N = 0;
	cin >> M >> N;
	vector<vector<int>> map(M, vector<int>(N, 0));
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	/* DFS + DP */
	vector<vector<int>> dp(M, vector<int>(N, -1));
	cout << DFS(0, 0, M, N, dp, map);

	return 0;
}

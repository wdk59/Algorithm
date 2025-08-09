#include <iostream>
#include <vector>
using namespace std;

int INF = 1000000000;

int DP_TSP(int cur, int visited, int& N, vector<vector<int>>& W, vector<vector<int>>& dp) {
	// visited의 모든 비트가 1: 모든 도시 방문 완료 -> 현재도시에서 시작도시로 돌아가는 비용 반환
	if (visited == (1 << N) - 1) {
		if (W[cur][0] != 0)
			return W[cur][0];
		else
			return INF;
	}

	if (dp[cur][visited] != -1)
		return dp[cur][visited];

	int result = INF;
	for (int i = 0; i < N; i++)
		if (!(visited & (1 << i)) && W[cur][i] != 0)
			result = min(result, DP_TSP(i, visited | (1 << i), N, W, dp) + W[cur][i]);
	
	return dp[cur][visited] = result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	int N = 0;
	cin >> N;
	vector<vector<int>> W(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> W[i][j];

	/* DP + 비트마스킹 + DFS */
	vector<vector<int>> dp(N, vector<int>(1 << N, -1));
	int answer = DP_TSP(0, 1, N, W, dp);
	cout << (answer == INF ? -1 : answer);

	return 0;
}

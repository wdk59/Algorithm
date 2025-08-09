#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 입력
	int n = 0;
	cin >> n;
	vector<pair<int, int>> mat(n, pair<int, int>(0, 0));
	for (int i = 0; i < n; i++)
		cin >> mat[i].first >> mat[i].second;

	// DP (dp[i][j]: i번쨰부터 j번째 행렬까지 곱할 때 최소 연산 횟수
	vector<vector<int>> dp(n, vector<int>(n, 0));
	// cnt: 곱할 행렬의 개수 - 1
	for (int cnt = 0; cnt < n; cnt++) {
		for (int i = 0; i < n - 1 - cnt; i++) {
			int j = i + cnt + 1;	// 곱할 마지막 행렬의 인덱스
			dp[i][j] = 2147483647;	// int 최대값
			// k: 나눠진 기준 행렬 위치
			for (int k = i; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mat[i].first * mat[k].second * mat[j].second);
		}
	}

	// 출력: 전체 행렬(0 ~ n-1) 곱한 횟수
	cout << dp[0][n - 1];

	return 0;
}

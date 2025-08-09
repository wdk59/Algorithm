#include <iostream>
#include <vector>
#include <algorithm>
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

	// DP
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int cnt = 0; cnt < n; cnt++) {
		for (int i = 0; i < n - 1 - cnt; i++) {
			int j = i + cnt + 1;
			dp[i][j] = 2147483647;	// int 최대값
			for (int k = i; k < j; k++)
				dp[i][j] = min({ dp[i][j], dp[i][k] + dp[k + 1][j] + mat[i].first * mat[k].second * mat[j].second });
		}
	}

	// 출력
	cout << dp[0][n - 1];

	return 0;
}

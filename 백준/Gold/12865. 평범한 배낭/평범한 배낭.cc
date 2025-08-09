#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 입력
	int N = 0, K = 0;
	cin >> N >> K;
	vector<int> W(N + 1, 0), V(N + 1, 0);	// 1-based
	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	// DP
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));	// 1-based
	for (int k = 1; k <= K; k++) {
		for (int row = 1; row <= N; row++) {
			if (W[row] > k)	// 초과
				dp[row][k] = dp[row - 1][k];
			else	// 가능
				dp[row][k] = max(dp[row - 1][k - W[row]] + V[row], dp[row - 1][k]);
		}
	}

	// 출력
	cout << dp[N][K];

	return 0;
}

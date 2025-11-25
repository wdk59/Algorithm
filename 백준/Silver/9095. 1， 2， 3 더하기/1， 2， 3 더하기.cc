#include <iostream>
#include <vector>
using namespace std;

void DP(vector<int>& dp) {
	dp[0] = 0;
	dp[1] = 1;	// 1
	dp[2] = 2;	// 1+1, 2
	dp[3] = 4;	// 1+1+1, 1+2, 2+1, 3
	for (int i = 4; i < dp.size(); i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	vector<int> dp(12, 0);	// 0 ~ 11
	int T = 0;
	cin >> T;

	/* 풀이, 출력 */
	DP(dp);

	int temp = 0;
	while (T--) {
		cin >> temp;
		cout << dp[temp] << '\n';
	}

	return 0;
}

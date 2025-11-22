#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/* 입력 */
	int num = 0;
	cin >> num;
	vector<int> stairs(num, 0), dp(num, 0);
	for (int i = 0; i < num; i++)
		cin >> stairs[i];

	/* 풀이 */
	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	dp[2] = max(stairs[2] + stairs[1], stairs[2] + stairs[0]);
	for (int i = 3; i < num; i++)
		dp[i] = max(stairs[i] + dp[i - 2], stairs[i] + dp[i - 3] + stairs[i - 1]);

	/* 출력 */
	cout << dp[num - 1];

	return 0;
}

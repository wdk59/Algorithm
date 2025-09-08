#include <iostream>
#include <vector>
using namespace std;

void dp(vector<int>& dp_cnt, int n) {
	if (n % 3 == 0 && n / 3 >= 1)
		dp_cnt[n] = min(dp_cnt[n], dp_cnt[n / 3] + 1);
	if (n % 2 == 0 && n / 2 >= 1)
		dp_cnt[n] = min(dp_cnt[n], dp_cnt[n / 2] + 1);
	if (n > 1)
		dp_cnt[n] = min(dp_cnt[n], dp_cnt[n - 1] + 1);

	if (dp_cnt[n] > 1000000) {
		int cnt = 0, tmp = n;
		while (tmp != 1) {
			if (tmp % 3 == 0)
				tmp /= 3;
			else if (tmp % 2 == 0)
				tmp /= 2;
			else
				tmp--;
			cnt++;
		}
		dp_cnt[n] = cnt;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/* 입력 */
	int N = 0;
	cin >> N;

	/* 풀이 */
	vector<int> dp_cnt(N + 1, 1000001);	// 1-based
	dp_cnt[1] = 0;
	for (int i = 2; i <= N; i++)
		dp(dp_cnt, i);

	/* 출력 */
	cout << dp_cnt[N];

	return 0;
}

#include <iostream>
#include <unordered_map>
using namespace std;

long long DP_solve(unordered_map<long long, long long>& dp, long long p, long long q, long long now) {
	// A0 = 1
	if (now == 0) {
		return 1;
	}

	// 이전에 계산했던 결과가 있으면 반환
	if (dp.find(now) != dp.end()) {
		return dp[now];
	}

	// 없으면 메모리에 추가하고 반환
	dp[now] = DP_solve(dp, p, q, now / p) + DP_solve(dp, p, q, now / q);
	return dp[now];
}

int main() {
	/* 입력 */
	long long N = 0, P = 0, Q = 0;
	cin >> N >> P >> Q;

	/* DP */
	// 메모이제이션
	unordered_map<long long, long long> DP;

	cout << DP_solve(DP, P, Q, N);

	return 0;
}
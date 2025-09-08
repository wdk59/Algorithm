#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/* 입력 */
	int N = 0, K = 0;
	cin >> N >> K;
	vector<int> coins(N, 0);
	for (int i = 0; i < N; i++)
		cin >> coins[i];

	/* 풀이 */
	int cnt = 0, idx = coins.size() - 1;
	while (K > 0 && idx >= 0) {
		if (K >= coins[idx]) {
			K -= coins[idx];
			cnt++;
		}
		else {
			idx--;
		}
	}

	/* 출력 */
	cout << cnt;

	return 0;
}

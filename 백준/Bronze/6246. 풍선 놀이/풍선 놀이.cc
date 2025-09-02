#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/* 입력 */
	int N = 0, Q = 0, L = 0, I = 0;
	cin >> N >> Q;
	vector<bool> balloons(N + 1, false);	// 1-based

	/* 풍선 설치 */
	while (Q-- > 0) {
		cin >> L >> I;
		if (!balloons[L])	balloons[L] = true;
		for (int i = L + 1; i < N + 1; i++)
			if ((i - L) % I == 0 && !balloons[i])
				balloons[i] = true;
	}

	/* 빈 공간 세기 */
	int answer = 0;
	for (int i = 1; i < N + 1; i++)
		if (!balloons[i])
			answer++;

	/* 출력 */
	cout << answer;

	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	int N = 0;
	cin >> N;
	vector<int> weights(N, 0); // 추의 무게
	for (int i = 0; i < N; i++)
		cin >> weights[i];

	/* 측정 가능 무게 계산 */
	// 추 무게 오름차순 정렬
	sort(weights.begin(), weights.end());

	int sum = 0;	// 측정 가능 무게
	for (int i = 0; i < N; i++) {
		// 현재까지 측정 가능 무게로 측정 가능한 추인지 검사
		if (weights[i] > sum + 1)
			break;

		// 무게 범위 확장
		sum += weights[i];
	}

	/* 출력: 측정 불가능한 최소 무게 (측정 가능 무게 + 1) */
	cout << sum + 1;

	return 0;
}

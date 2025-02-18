// DP
// 내 부분수열 크기 = 나보다 작은 거의 부분수열 크기 + 나

#include <iostream>
using namespace std;

int main() {
	int size = 0;	// 수열의 크기
	int arr[1002];	// 수열
	int dp[1002];	// 각 인덱스별 가장 긴 부분수열의 크기 저장

	// input
	cin >> size;
	for (int i = 1; i <= size; i++) {
		cin >> arr[i];
	}

	// solve
	int answer = 0;
	for (int i = 1; i <= size; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);	// 자기자신(i)도 길이에 포함
			}
		}
		answer = max(dp[i], answer);
	}

	cout << answer << endl;

	return 0;
}
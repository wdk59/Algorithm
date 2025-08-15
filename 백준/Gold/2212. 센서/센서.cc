#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, K = 0;
	cin >> N >> K;

	vector<int> sensors(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> sensors[i];
	}

	sort(sensors.begin(), sensors.end());

	vector<int> diffs(N - 1, 0);
	for (int i = 0; i < N - 1; i++)
		diffs[i] = sensors[i + 1] - sensors[i];

	sort(diffs.begin(), diffs.end(), greater<int>());

	int result = 0;
	for (int i = K - 1; i < N - 1; i++)
		result += diffs[i];

	cout << result;
	return 0;
}

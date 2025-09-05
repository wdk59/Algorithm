#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	int N = 0, sum = 0;
	cin >> N;
	vector<int> nums(N, 0);
	int numsCnt[8001] = { 0, };	// 4000번 인덱스를 0번으로 씀
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		sum += nums[i];
		numsCnt[nums[i] + 4000]++;
	}
	sort(nums.begin(), nums.end());

	/* 풀이 */
	// 최빈값 구하기
	int mode = 0;
	vector<int> modes;
	for (int i = 0; i < 8001; i++)
		if (mode < numsCnt[i])
			mode = numsCnt[i];
	for (int i = 0; i < 8001; i++)
		if (mode == numsCnt[i])
			modes.push_back(i - 4000);

	/* 출력 */
	cout << (round((double)sum / N) == -0 ? 0 : round((double)sum / N)) << '\n';
	cout << nums[N / 2] << '\n';
	cout << (modes.size() > 1 ? modes[1] : modes[0]) << '\n';
	cout << nums[N - 1] - nums[0];

	return 0;
}

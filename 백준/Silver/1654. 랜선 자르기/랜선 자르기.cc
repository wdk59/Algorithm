#include <iostream>
#include <vector>
#include <algorithm>	// max_element
using namespace std;

int main() {
	int k = 0, n = 0;
	vector<int> lines;

	cin >> k >> n;
	lines.resize(k);
	
	for (int i = 0; i < k; i++)
		cin >> lines[i];

	// lines의 최소와 최대 길이가 차이가 많이 나면 짧은 걸 안 쓸 수도 있음 -> max를 가장 긴 줄의 길이로 설정할 것!
	long long min = 1, max = *max_element(lines.begin(), lines.end());
	int cnt = 0, result = 0;
	while (min <= max) {
		cnt = 0;	// 이거 안 해줘서 무한루프 걸렸었음
		for (int i = 0; i < k; i++) {
			cnt += lines[i] / ((min + max) / 2);
		}
		if (cnt < n) {
			max = (min + max) / 2 - 1;
		}
		else {	// 필요한 만큼 만들 수 있는 경우
			result = (min + max) / 2;
			min = (min + max) / 2 + 1;
		}
	}

	cout << result;

	return 0;
}

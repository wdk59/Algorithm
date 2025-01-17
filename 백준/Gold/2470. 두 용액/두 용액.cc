#include <iostream>
#include <vector>	// pair, vector
#include <algorithm>	// sort()
using namespace std;

int main() {
	int N = 0;
	cin >> N;
	vector<int> sols(N);	// 입력받을 용액 특성값 벡터
	for (int i = 0; i < N; i++)
		cin >> sols[i];
	sort(sols.begin(), sols.end());

	pair<int, int> result;
	result = make_pair(0, 0);
	int closest = 2000000001;	// 용액쌍의 합 중 0에 가장 가까운 수의 절대값

	int left = 0, right = N - 1;

	if (sols[left] >= 0) {
		result = make_pair(sols[left], sols[left + 1]);
	}
	else if (sols[right] <= 0) {
		result = make_pair(sols[right - 1], sols[right]);
	}
	else {
		// left와 right가 같아지면 같은 값을 더하게 되므로 반복 범위는 left < right
		while (left < right) {
			if (abs(sols[left] + sols[right]) < closest) {
				closest = abs(sols[left] + sols[right]);
				result = make_pair(sols[left], sols[right]);
			}

			if (sols[left] + sols[right] < 0) {
				left++;
			}
			else if (sols[left] + sols[right] > 0) {
				right--;
			}
			else {
				break;
			}
		}
	}

	cout << result.first << " " << result.second;

	return 0;
}

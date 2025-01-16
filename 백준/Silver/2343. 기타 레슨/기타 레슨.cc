#include <iostream>
#include <vector>
#include <numeric>	// accumulate
#include <algorithm>	// max_element
using namespace std;

int main() {
	int N = 0, M = 0, result = 0;
	vector<int> lec;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		cin >> tmp;
		lec.push_back(tmp);
	}

	int left = *max_element(lec.begin(), lec.end()), right = accumulate(lec.begin(), lec.end(), 0);
	while (left <= right) {
		int mid = (left + right) / 2;
		int time = 0;	// �� ��緹�̿� ���� ���� �� �ð�
		int cnt = 1;	// ���Ǵ� ��緹�� ��
		for (int i : lec) {
			if (time + i > mid) {
				cnt++;
				time = i;
			}
			else {
				time += i;
			}
		}

		if (cnt > M) {
			left = mid + 1;
		}
		else {
			result = mid;
			right = mid - 1;
		}
	}

	cout << result;

	return 0;
}
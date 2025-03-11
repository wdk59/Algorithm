#include <iostream>
using namespace std;

int main() {
	int N = 0, cnt = 0;

	cin >> N;
	int tmp = 0;
	bool flag = true;
	for (int i = 0; i < N; i++) {
		flag = true;
		cin >> tmp;

		// 소수인지 검사
		for (int j = 2; j <= tmp / 2; j++) {
			if (tmp % j == 0) {
				flag = false;
				break;
			}
		}
		if (tmp < 2 || !flag)
			continue;

		cnt++;
	}

	cout << cnt;

	return 0;
}

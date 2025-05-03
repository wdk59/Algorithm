#include <iostream>
using namespace std;

int main() {
	int N = 0, cnt = 0;
	cin >> N;

	for (int i = N; i > 1; i--) {
		if (i % 5 == 0) {
			cnt++;

			if (i % 25 == 0) {
				cnt++;
				
				if (i % 125 == 0)
					cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}
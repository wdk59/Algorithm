#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = 0, s = 0;
	vector<int> noMulti;

	cin >> n >> s;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		noMulti.push_back(tmp);
	}

	int length = n + 1;
	int start = 0, end = 0;
	int sum = noMulti[0];
	while (start <= end && end < n) {
		if (sum < s) {
			if (end == n - 1) {
				sum -= noMulti[start++];
				continue;
			}
			sum += noMulti[++end];
		}
		else {
			if (length > end - start + 1) { length = end - start + 1; }
			sum -= noMulti[start++];
		}
	}

	if (length == n + 1) { length = 0; }

	cout << length;

	return 0;
}

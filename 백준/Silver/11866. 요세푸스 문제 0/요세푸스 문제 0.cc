#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, K = 0;
	cin >> N >> K;

	int idx = 0, cnt = 0, delNum = 0;
	vector<bool> deleted(N, false);
	cout << "<";
	while (delNum < N) {
		cnt = 0;
		while (cnt < K - 1 || deleted[idx]) {
			if (!deleted[idx])
				cnt++;
			idx = (idx < N - 1 ? idx + 1 : 0);
		}
		delNum++;
		deleted[idx] = true;
		cout << idx + 1;
		if (delNum < N)
			cout << ", ";
	}
	cout << ">";

	return 0;
}

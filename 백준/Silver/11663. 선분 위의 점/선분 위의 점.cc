#include <iostream>
#include <vector>
#include <algorithm>	// sort
using namespace std;

vector<int> dots;

int search(int goal, bool isStart) {
	int p = 0;
	int left = 0, right = dots.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (dots[mid] < goal) {
			p = mid + 1;
			left = mid + 1;
		}
		else if (dots[mid] > goal) {
			right = mid - 1;
		}
		else {
			return isStart ? mid : mid + 1;
		}
	}

	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		dots.push_back(tmp);
	}
	sort(dots.begin(), dots.end());

	for (int i = 0; i < m; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
	
		cout << search(end, false) - search(start, true) << "\n";
	}

	return 0;
}

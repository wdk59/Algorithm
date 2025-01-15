#include <iostream>
#include <vector>
#include <algorithm>	// sort
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	vector<int> dots;

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
	
		cout <<  upper_bound(dots.begin(), dots.end(), end) - lower_bound(dots.begin(), dots.end(), start) << "\n";
	}

	return 0;
}

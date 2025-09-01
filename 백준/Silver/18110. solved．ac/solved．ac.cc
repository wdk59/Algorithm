#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	vector<int> op;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		op.push_back(tmp);
	}
	sort(op.begin(), op.end());

	int ex = floor(n * 0.15 + 0.5);
	float sum = 0;
	for (int i = ex; i < n - ex; i++)
		sum += op[i];
	cout << floor(sum / (n - 2 * ex) + 0.5);
	
	return 0;
}

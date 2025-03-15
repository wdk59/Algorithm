#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> x, y;
	int N = 0;
	cin >> N;
	int tmpX = 0, tmpY = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmpX >> tmpY;
		x.push_back(tmpX);
		y.push_back(tmpY);
	}

	int xLength = *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end());
	int yLength = *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end());
	cout << xLength * yLength;

	return 0;
}

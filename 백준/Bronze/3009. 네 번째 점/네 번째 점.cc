#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> x, y;
	int tmpX = 0, tmpY = 0;

	for (int i = 0; i < 3; i++) {
		cin >> tmpX >> tmpY;
		x.push_back(tmpX);
		y.push_back(tmpY);
	}

	for (int i = 0; i < 3; i++) {
		if (count(x.begin(), x.end(), x[i]) == 1)
			cout << x[i] << ' ';
	}
	for (int i = 0; i < 3; i++) {
		if (count(y.begin(), y.end(), y[i]) == 1)
			cout << y[i];
	}

	return 0;
}

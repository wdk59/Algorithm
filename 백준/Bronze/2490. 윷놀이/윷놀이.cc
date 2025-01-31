#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		vector<int> yut(4);
		for (int j = 0; j < 4; j++) {
			int tmp = 0;
			cin >> tmp;
			yut.push_back(tmp);
		}

		switch (count(yut.begin(), yut.end(), 1)) {
		case 0:
			cout << 'D' << endl;
			break;
		case 1:
			cout << 'C' << endl;
			break;
		case 2:
			cout << 'B' << endl;
			break;
		case 3:
			cout << 'A' << endl;
			break;
		case 4:
			cout << 'E' << endl;
			break;
		default:
			cout << 'Z' << endl;
			break;
		}
	}

	return 0;
}
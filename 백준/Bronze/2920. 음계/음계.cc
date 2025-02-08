#include <iostream>
#include <string>
using namespace std;

int main() {
	int num = 0;
	cin >> num;

	if (num == 1) {
		for (int i = 2; i <= 8; i++) {
			cin >> num;
			if (num != i) {
				cout << "mixed";
				break;
			}

			if (i == 8) {
				cout << "ascending";
			}
		}
	}
	else if (num == 8) {
		for (int i = 7; i >= 1; i--) {
			cin >> num;
			if (num != i) {
				cout << "mixed";
				break;
			}

			if (i == 1) {
				cout << "descending";
			}
		}
	}
	else {
		cout << "mixed";
	}

	return 0;
}

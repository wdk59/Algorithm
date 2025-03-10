#include <iostream>
#include <string>
using namespace std;

int main() {
	int coins[4] = { 25, 10, 5, 1 };
	int T = 0, C = 0;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> C;
		
		for (int type : coins) {
			cout << C / type << ' ';
			C %= type;
		}
		cout << '\n';
	}

	return 0;
}

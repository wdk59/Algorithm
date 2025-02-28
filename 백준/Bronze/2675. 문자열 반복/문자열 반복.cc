#include <iostream>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	int R = 0;
	string str = "";
	for (int i = 0; i < T; i++) {
		cin >> R >> str;
		for (int j = 0; j < str.size(); j++) {
			for (int k = 0; k < R; k++)
				cout << str[j];
		}
		cout << '\n';
	}

	return 0;
}
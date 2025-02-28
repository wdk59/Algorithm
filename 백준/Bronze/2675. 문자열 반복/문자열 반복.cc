#include <iostream>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	int R = 0;
	string str = "", result = "";
	for (int i = 0; i < T; i++) {
		result = "";
		cin >> R >> str;
		for (int j = 0; j < str.size(); j++) {
			result.append(R, str[j]);
		}
		cout << result << '\n';
	}

	return 0;
}
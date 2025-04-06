#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		(str[i] >= 65 && str[i] <= 90) ? str[i] += 32 : str[i] -= 32;
	}

	cout << str;
}
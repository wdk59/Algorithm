#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	while (true) {
		string tmp = "";
		cin >> tmp;

		if (tmp == "0")
			break;

		bool success = true;
		for (int i = 0; i < tmp.length(); i++) {
			if (tmp[i] != tmp[tmp.length() - 1 - i]) {
				success = false;
			}
		}
		if (success)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}

#include <iostream>
using namespace std;

int main() {
	string characters[5];

	for (int i = 0; i < 5; i++)
		cin >> characters[i];

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (characters[j].size() > i)
				cout << characters[j][i];
		}
	}

	return 0;
}

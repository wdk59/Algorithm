#include <iostream>
using namespace std;

int main() {
	char characters[5][16] = {};

	int maxSize = 0, cnt = 0;
	for (int i = 0; i < 5; i++) {
		cin >> characters[i];
		cnt = 0;
		while (characters[i][cnt] != '\0')
			cnt++;
		maxSize = max(maxSize, cnt);
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (characters[j][i] != '\0')
				cout << characters[j][i];
		}
	}

	return 0;
}

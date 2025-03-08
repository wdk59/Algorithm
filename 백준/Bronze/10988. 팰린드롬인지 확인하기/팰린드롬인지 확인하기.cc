#include <iostream>
using namespace std;

int main() {
	string word;
	cin >> word;

	int i = 0;
	for (i = 0; i < word.size() / 2; i++) {
		if (word[i] != word[word.size() - 1 - i])
			break;
	}

	cout << (i == word.size() / 2 ? 1 : 0);

	return 0;
}

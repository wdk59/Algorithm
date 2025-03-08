#include <iostream>
using namespace std;

int main() {
	string N;
	int B = 0;
	cin >> N >> B;

	int result = 0;
	for (int i = 0; i < N.size(); i++) {
		result *= B;
		if (isdigit(N[i]))
			result += N[i] - '0';
		else
			result += N[i] - 'A' +10;
	}

	cout << result;

	return 0;
}

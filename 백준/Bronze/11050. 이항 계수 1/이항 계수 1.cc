#include <iostream>
using namespace std;

int factorial(int num) {
	int result = 1;
	for (int i = num; i > 1; i--)
		result *= i;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, K = 0;
	cin >> N >> K;
	cout << factorial(N) / (factorial(N - K) * factorial(K));

	return 0;
}

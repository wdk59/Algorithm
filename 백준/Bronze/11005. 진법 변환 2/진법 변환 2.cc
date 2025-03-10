#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	int B = 0;
	cin >> N >> B;

	string result = "";
	while (N > 0) {
		if (N % B < 10)
			result += to_string(N % B);
		else
			result += (N % B - 10 + 'A');	// 10부터 'A'로 표기
		N /= B;
	}

	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i];

	return 0;
}

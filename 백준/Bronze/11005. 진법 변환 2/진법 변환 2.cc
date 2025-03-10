#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	int B = 0;
	cin >> N >> B;

	string result = "";
	// N을 B로 나눈 나머지가 양수일 때까지 반복
	while (N >= B) {
		if (N % B < 10)
			result = to_string(N % B) + result;
		else
			result = (char)(N % B - 10 + 'A') + result;	// 10부터 'A'로 표기하기 때문에 10진법에서 10만큼 뺀 다음 'A'의 아스키코드만큼 더해준다.
		N /= B;
	}
	if (N < 10)
		result = to_string(N) + result;
	else
		result = (char)(N - 10 + 'A') + result;

	cout << result;

	return 0;
}

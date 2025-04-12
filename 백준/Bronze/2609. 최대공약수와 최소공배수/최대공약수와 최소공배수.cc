#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num[2] = { 0, }, tmpA = 0, tmpB;
	cin >> num[0] >> num[1];
	if (num[0] > num[1]) {
		tmpA = num[0];
		num[0] = num[1];
		num[1] = tmpA;
	}

	int divisor = 1;
	tmpA = num[0]; tmpB = num[1];
	for (int i = 2; i <= num[0]; i++) {
		while (tmpA % i == 0 && tmpB % i == 0) {
			divisor *= i;
			tmpA /= i;
			tmpB /= i;
		}
		while (tmpA % i == 0)
			tmpA /= i;
		while (tmpB % i == 0)
			tmpB /= i;
	}

	int multipleA = 1, multipleB = 1;
	while (multipleA * num[0] != multipleB * num[1])
		multipleA* num[0] > multipleB* num[1] ? multipleB++ : multipleA++;
	cout << divisor << '\n' << multipleA * num[0];

	return 0;
}

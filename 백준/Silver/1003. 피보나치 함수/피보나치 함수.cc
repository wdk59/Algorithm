#include <iostream>
using namespace std;

void DP_BottomUp_ZeroOne(int *zero, int *one) {
	zero[0] = one[1] = 1;	// 0 또는 1일 때는 다른 수는 반환하지 않으므로 각자 수에서 하나씩 반환 

	/* 2부터 40까지 각 수에서 반환되는 0과 1의 수 구하기 */
	// 0과 1을 이전 수와 그 전 수를 구할 때 반환했던 만큼 또 반환하기 때문에 이전 결과값 둘을 더함
	// -> fib(n) = fib(n-2) + fib(n-1) 이기 때문 
	for (int i = 2; i <= 40; i++) {
		zero[i] = zero[i - 2] + zero[i - 1];
		one[i] = one[i - 2] + one[i - 1];
	}
}

int main() {
	int zero[41] = { 0, }, one[41] = { 0, };
	DP_BottomUp_ZeroOne(zero, one);

	int T = 0, input = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> input;
		cout << zero[input] << ' ' << one[input] << '\n';
	}
	
	return 0;
}

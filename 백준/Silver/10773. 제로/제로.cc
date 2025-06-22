#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int cnt = 0, num = 0, sum = 0;
	stack<int> nums;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		if (num != 0) {
			sum += num;
			nums.push(num);
		}
		else {
			sum -= nums.top();
			nums.pop();
		}
	}
	
	cout << sum;

	return 0;
}

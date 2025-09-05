#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	int N = 0;
	cin >> N;
	vector<int> nums(N, 0);
	for (int i = 0; i < N; i++)
		cin >> nums[i];

	/* 풀이 */
	stack<int> st;
	st.push(1);
	string answer = "+\n";
	int target = 0, num = 1;
	while (num <= N && !st.empty()) {
		if (st.top() < nums[target]) {
			st.push(++num);
			answer += "+\n";
		}
		else if (st.top() == nums[target++]) {
			st.pop();
			answer += "-\n";
			if (st.empty() && num < N) {
				st.push(++num);
				answer += "+\n";
			}
		}
		else {
			answer = "NO";
			break;
		}
	}

	/* 출력 */
	cout << answer;

	return 0;
}

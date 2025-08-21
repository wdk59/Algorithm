#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	string op = "";
	int input = 0;
	queue<int> q;
	while (N-- > 0) {
		cin >> op;
		
		if (op == "push") {
			cin >> input;
			q.push(input);
		}
		else if (op == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (op == "size") {
			cout << q.size() << '\n';
		}
		else if (op == "empty") {
			cout << (q.empty() ? 1 : 0) << '\n';
		}
		else if (op == "front") {
			cout << (q.empty() ? -1 : q.front()) << '\n';
		}
		else if (op == "back") {
			cout << (q.empty() ? -1 : q.back()) << '\n';
		}
	}

	return 0;
}

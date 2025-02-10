#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> stack;
	int N = 0;
	cin >> N;

	int op = 0, x = 0;
	for (int i = 0; i < N; i++) {
		cin >> op;
		if (op == 1) {
			cin >> x;
			stack.push_back(x);
		}
		else if (op == 2) {
			if (stack.size() == 0)
			{
				cout << -1 << "\n";
			}
			else {
				cout << stack[stack.size() - 1] << "\n";
				stack.erase(stack.end() - 1);
			}
		}
		else if (op == 3) {
			cout << stack.size() << "\n";
		}
		else if (op == 4) {
			if (stack.size() == 0) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (op == 5) {
			if (stack.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << stack[stack.size() - 1] << "\n";
			}
		}
	}

	return 0;
}

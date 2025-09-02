#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		int m = min(a, b);
		cout << (m - 1) * 2 << '\n';
	}

	return 0;
}

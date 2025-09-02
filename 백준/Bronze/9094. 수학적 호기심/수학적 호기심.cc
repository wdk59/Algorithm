#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/* 입력 */
	int t = 0, n = 0, m = 0, cnt = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cnt = 0;
		cin >> n >> m;
		for (int a = 1; a < n - 1; a++)
			for (int b = a + 1; b < n; b++)
				if ((a * a + b * b + m) % (a * b) == 0)
					cnt++;
		cout << cnt << '\n';
	}

	return 0;
}

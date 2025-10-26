#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	int answer = 0, T = 0;
	cin >> T;

	/* 풀이 */
	int N = 0, D = 0;
	int v = 0, f = 0, c = 0;
	while (T--) {
		answer = 0;
		cin >> N >> D;
		while (N--) {
			cin >> v >> f >> c;
			if ((float)D / v * c <= f)
				answer++;
		}
		cout << answer << '\n';
	}

	return 0;
}

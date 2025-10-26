#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	int N = 0;
	cin >> N;

	/* 풀이 */
	bool flag = false;
	int num = 0, tmp = 0;
	while (N--) {
		unordered_map<int, int> a, b;
		cin >> num;
		while (num--) {
			cin >> tmp;
			a[tmp]++;
		}
		cin >> num;
		while (num--) {
			cin >> tmp;
			b[tmp]++;
		}

		for (int i = 4; i > 0; i--) {
			if (a[i] != b[i]) {
				cout << (a[i] < b[i] ? 'B' : 'A') << '\n';
				flag = true;
				break;
			}
		}
		if (flag)
			flag = false;
		else
			cout << "D\n";
	}

	return 0;
}

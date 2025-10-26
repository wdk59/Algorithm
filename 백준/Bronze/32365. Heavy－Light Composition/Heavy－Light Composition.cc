#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	int T = 0, N = 0;
	cin >> T >> N;

	/* 풀이 */
	string str = "";
	while (T--) {
		unordered_map<char, int> cnt;
		cin >> str;
		for (int i = 0; i < N; i++)
			cnt[str[i]]++;
		for (int i = 1; i < N; i++) {
			if (cnt[str[0]] == 1) {
				if ((i % 2 == 0 && cnt[str[i]] > 1) || (i % 2 == 1 && cnt[str[i]] == 1)) {
					cout << "F\n";
					break;
				}
			} else if (cnt[str[0]] > 1) {
				if ((i % 2 == 0 && cnt[str[i]] == 1) || (i % 2 == 1 && cnt[str[i]] > 1)) {
					cout << "F\n";
					break;
				}
			}
			if (i == str.size() - 1) {
				cout << "T\n";
			}
		}
	}

	return 0;
}

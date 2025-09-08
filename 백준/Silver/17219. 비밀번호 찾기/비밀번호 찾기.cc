#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/* 입력 */
	int N = 0, M = 0;
	cin >> N >> M;
	unordered_map<string, string> memo;
	string url = "", pw = "";
	for (int i = 0; i < N; i++) {
		cin >> url >> pw;
		memo[url] = pw;
	}

	/* 풀이, 출력 */
	for (int i = 0; i < M; i++) {
		cin >> url;
		cout << memo[url] << '\n';
	}

	return 0;
}

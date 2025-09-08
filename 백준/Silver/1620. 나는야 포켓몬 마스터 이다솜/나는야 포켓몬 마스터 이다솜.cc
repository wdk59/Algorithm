#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/* 입력 */
	int N = 0, M = 0;
	cin >> N >> M;

	/* 풀이 */
	unordered_map<string, string> monsters;
	string tmp = "";
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		monsters[tmp] = to_string(i + 1);
		monsters[to_string(i + 1)] = tmp;
	}

	/* 출력 */
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		cout << monsters[tmp] << '\n';
	}

	return 0;
}

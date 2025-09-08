#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/* 입력 */
	int N = 0, M = 0;
	cin >> N >> M;
	unordered_map<string, bool> haveSeen;
	string tmp = "";
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		haveSeen[tmp] = true;
	}

	/* 풀이 */
	vector<string> result;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (haveSeen[tmp])
			result.push_back(tmp);
	}
	sort(result.begin(), result.end());

	/* 출력 */
	cout << result.size() << '\n';
	for (string name : result)
		cout << name << '\n';

	return 0;
}

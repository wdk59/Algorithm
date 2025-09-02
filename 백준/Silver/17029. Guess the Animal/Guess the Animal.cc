#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int num_common(vector<string> a, vector<string> b) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			if (a[i] == b[j])
				cnt++;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	int N = 0;
	cin >> N;

	vector<vector<string>> characteristics;
	string name = "";
	int K = 0;
	for (int i = 0; i < N; i++) {
		cin >> name >> K;
		characteristics.push_back(vector<string>(K, ""));
		for (int j = 0; j < K; j++)
			cin >> characteristics[i][j];
	}

	/* 모든 동물쌍에 대한 공통 특성의 최대값 찾기 */
	int answer = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			answer = max(answer, num_common(characteristics[i], characteristics[j]));

	cout << answer + 1;

	return 0;
}

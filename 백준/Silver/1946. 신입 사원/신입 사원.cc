#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
	int T = 0, N = 0;
	cin >> T;

	for (int i = 0; i < T; i++) {
		vector<pair<int, int>> rank;	// first: 서류, second: 면접
		cin >> N;
		for (int j = 0; j < N; j++) {
			int a = 0, b = 0;
			cin >> a >> b;
			rank.push_back(make_pair(a, b));
		}

		// 서류 순위(first) 기준으로 정렬
		sort(rank.begin(), rank.end());

		// 면접 순위(second) 비교
		int best = 100001;
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (rank[j].second < best) {
				cnt++;
				best = rank[j].second;
			}
		}

		// 결과 출력
		cout << cnt << "\n";
	}

	return 0;
}
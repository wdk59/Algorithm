#include <iostream>
#include <vector>	// 우선순위 큐는 중복 불허
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/* 입력 */
	int T = 0;
	cin >> T;

	/* 풀이 */
	int tmp = 0, N = 0, M = 0, cnt = 1, left = 0;
	bool isFirst = true;
	vector<int> q;
	while (T--) {
		cnt = 1; left = 0;
		q = vector<int>();
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			q.push_back(tmp);
		}
		while (left < q.size()) {
			isFirst = true;
			for (int i = left + 1; i < q.size(); i++) {
				if (q[i] > q[left]) {
					isFirst = false;
					break;
				}
			}
			if (isFirst) {
				if (left == M) {
					cout << cnt << '\n';
					break;
				}
				else {
					cnt++; left++;
				}
			}
			else {
				if (left == M)
					M = q.size();
				q.push_back(q[left++]);
			}
		}
	}


	return 0;
}

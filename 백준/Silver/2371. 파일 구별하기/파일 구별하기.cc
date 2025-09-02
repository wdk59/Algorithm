#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	int N = 0;
	cin >> N;

	vector<vector<int>> files(N, vector<int>());
	int tmp = 0, maxSize = 0;
	for (int i = 0; i < N; i++) {
		while (cin >> tmp && tmp != -1)
			files[i].push_back(tmp);
		if (maxSize < files[i].size())
			maxSize = files[i].size();
	}

	/* K번째 수까지 비교해보면서 K 늘리기 */
	int K = 0;
	while (K++ < maxSize) {
		set<vector<int>> exist;
		bool isExist = false;

		// 각 파일에 대해  K번째 수까지 비교
		for (int i = 0; i < N; i++) {
			vector<int> cutFile(files[i].begin(), files[i].begin() + min(K, (int)files[i].size()));
			while (cutFile.size() <= K)
				cutFile.push_back(0);

			// 같은 파일 존재 여부 검사
			if (exist.count(cutFile)) {
				isExist = true;
				break;
			}
			exist.insert(cutFile);
		}

		// 현재 K로 모든 파일 구별 가능하다면 종료
		if (!isExist)
			break;
	}

	/* 출력 */
	cout << K;

	return 0;
}

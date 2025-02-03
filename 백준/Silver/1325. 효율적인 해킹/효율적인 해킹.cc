#include <iostream>
#include <vector>
#include <cstring>	// memset()
using namespace std;

vector<int> computers[10001];
bool visited[10001];

int DFS(int num) {
	/* 이미 해킹한 컴퓨터일 때 */
	if (visited[num]) {
		return 0;
	}

	/* 해킹해야 하는 컴퓨터일 때 */
	visited[num] = true;	// 방문 표시
	int cnt = 1;	// 방문한 컴퓨터를 개수에 포함

	for (int i = 0; i < computers[num].size(); i++) {
		cnt += DFS(computers[num][i]);
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	cin >> N >> M;

	// 신뢰 관계 입력
	for (int i = 0; i < M; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		computers[b].push_back(a);
	}

	/* 해킹 시뮬레이션 */
	int max = 0;
	vector<int> result;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		cnt = DFS(i);	// i번째 컴퓨터를 해킹했을 때 해킹할 수 있는 컴퓨터의 수

		// 현재 최대값과 비교
		if (cnt < max) {
			continue;
		}
		else if (cnt > max) {
			max = cnt;
			result = vector<int>();
		}
		result.push_back(i);
	}

	/* 결과 출력 */
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}
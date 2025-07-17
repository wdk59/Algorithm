// 구상: 4분 28초
#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000001

struct NODE {
	int departure = 0;
	int arrival = 0;
	int cost = INF;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;
	
	// 노선 입력
	vector<NODE> route(m, { 0, 0, INF });
	for (int i = 0; i < m; i++)
		cin >> route[i].departure >> route[i].arrival >> route[i].cost;

	// table 초기값 설정
	vector<vector<int>> table(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < m; i++)
		table[route[i].departure][route[i].arrival] = min(table[route[i].departure][route[i].arrival], route[i].cost);
	// 본인->본인은 가중치 0
	for (int i = 1; i < n + 1; i++)
		table[i][i] = 0;

	// 플로이드 워셜
	for (int k = 1; k < n + 1; k++)
		for (int i = 1; i < n + 1; i++)
			for (int j = 1; j < n + 1; j++)
				table[i][j] = min(table[i][j], table[i][k] + table[k][j]);

	// 출력
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++)
			cout << (table[i][j] < INF ? table[i][j] : 0) << ' ';
		cout << '\n';
	}

    return 0;
}
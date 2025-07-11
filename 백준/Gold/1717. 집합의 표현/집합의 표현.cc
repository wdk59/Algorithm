// 구상: 약 8분
#include <iostream>
#include <vector>

using namespace std;

int getRoot(vector<int>& nodes, int x) {
	if (nodes[x] == x)
		return x;
	return nodes[x] = getRoot(nodes, nodes[x]);	// nodes[x] 값 갱신해줘서 그래프가 깊어지는 것 방지
}

void unionSet(vector<int>& nodes, int a, int b) {
	a = getRoot(nodes, a);
	b = getRoot(nodes, b);

	if (a != b)
		nodes[b] = nodes[a];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> nodes(n + 1);
	for (int i = 0; i <= n; i++)
		nodes[i] = i;

	int op = -1, a = -1, b = -1;
	while (m--) {
		cin >> op >> a >> b;

		if (op == 0)
			unionSet(nodes, a, b);
		else
			cout << (getRoot(nodes, a) == getRoot(nodes, b) ? "YES" : "NO") << '\n';
	}

	return 0;
}

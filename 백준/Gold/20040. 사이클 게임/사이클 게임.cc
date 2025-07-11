#include <iostream>
#include <vector>
using namespace std;

int findRoot(vector<int>& parent, int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findRoot(parent, parent[x]);
}

void unionSet(vector<int>& parent, int a, int b) {
	a = findRoot(parent, parent[a]);
	b = findRoot(parent, parent[b]);
	
	if (a != b)
		parent[b] = a;
}

bool makeCycle(vector<int>& parent, int a, int b) {
	if (findRoot(parent, parent[a]) == findRoot(parent, parent[b]))
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> parent(n, 0);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	
	int a = 0, b = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (makeCycle(parent, a, b)) {
			cout << i;
			return 0;
		}
		unionSet(parent, a, b);
	}
	cout << 0;

	return 0;
}

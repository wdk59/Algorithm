#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<bool> valid;

void erase(int node) {
	valid[node] = false;
	for (int i = 0; i < tree[node].size(); i++) {
		valid[tree[node][i]] = false;
	}
}

int DFS_count(int node, int cnt) {
	if (!valid[node]) {
		return 0;
	}
	
	// 리프 노드일 때
	if (tree[node].size() == 0) {
		return 1;
	}
	else if (tree[node].size() == 1 && !valid[tree[node][0]]) {
		return 1;
	}

	for (int i = 0; i < tree[node].size(); i++) {
		cnt += DFS_count(tree[node][i], 0);
	}

	return cnt;
}

int main() {
	int N = 0, ROOT = -1;
	cin >> N;
	tree.resize(N);
	valid.resize(N);

	for (int i = 0; i < N; i++) {
		int tmp = -2;
		cin >> tmp;
		if (tmp != -1) {
			tree[tmp].push_back(i);
		}
		else {
			ROOT = i;
		}
		valid[i] = true;
	}

	int eraseNode = 0;
	cin >> eraseNode;
	erase(eraseNode);

	cout << DFS_count(ROOT, 0);

	return 0;
}
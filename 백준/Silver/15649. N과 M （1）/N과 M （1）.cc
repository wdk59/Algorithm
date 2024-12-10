#include <iostream>
#include <vector>
using namespace std;

void find(int n, int m, vector<int> vec, int cnt, vector<bool> visited) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << vec[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				vector<int>::iterator it = vec.begin() + cnt;
				vec.insert(it, i);
				visited[i] = true;

				find(n, m, vec, cnt + 1, visited);
				visited[i] = false;
			}
		}
	}
}

int main() {
	int N = 0, M = 0;
	vector<int> vec;
	vector<bool> visited;
	visited.resize(9);

	cin >> N >> M;

	find(N, M, vec, 0, visited);

	return 0;
}

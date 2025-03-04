#include <iostream>
#include <vector>
#include <algorithm>	// reverse
using namespace std;

int main() {
	int N = 0, M = 0;
	cin >> N >> M;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		v.push_back(i + 1);
	}
	
	int start = 0, end = 0;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		reverse(v.begin() + start - 1, v.begin() + end);
	}

	for (int i : v) {
		cout << i << ' ';
	}

	return 0;
}

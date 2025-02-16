#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	cin >> N >> M;
	vector<int> basket;
	for (int i = 1; i <= N; i++) {
		basket.push_back(i);
	}

	int a = 0, b = 0, tmp = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		tmp = basket[a - 1];
		basket[a - 1] = basket[b - 1];
		basket[b - 1] = tmp;
	}

	for (int i = 0; i < N; i++) {
		cout << basket[i] << " ";
	}

	return 0;
}

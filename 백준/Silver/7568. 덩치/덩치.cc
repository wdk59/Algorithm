#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> info;
	int tmpX = 0, tmpY = 0, N = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmpX >> tmpY;
		info.push_back(make_pair(tmpX, tmpY));
	}

	int rank = 0;
	for (int i = 0; i < N; i++) {
		rank = 1;
		for (int j = 0; j < N; j++) {
			if (info[i].first < info[j].first && info[i].second < info[j].second)
				rank++;
		}
		cout << rank << ' ';
	}

	return 0;
}

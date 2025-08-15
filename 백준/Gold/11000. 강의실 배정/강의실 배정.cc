#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;
	vector<pair<int, int>> lectures(N, { 0, 0 });
	for (int i = 0; i < N; i++)
		cin >> lectures[i].first >> lectures[i].second;

	sort(lectures.begin(), lectures.end());
	// 작은 값부터 출력하는 pq
	priority_queue<int, vector<int>, greater<int>> endTime;

	for (int i = 0; i < N; i++) {
		if (!endTime.empty() && lectures[i].first >= endTime.top())
			endTime.pop();

		endTime.push(lectures[i].second);
	}

	cout << endTime.size();

	return 0;
}
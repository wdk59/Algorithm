#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> meetings(N);

	for (int i = 0; i < N; i++) {
		cin >> meetings[i].first >> meetings[i].second; // start, end
	}

	// 끝나는 시간 기준 오름차순, 끝나는 시간이 같으면 시작 시간 기준 오름차순
	sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	});

	int count = 0;
	int current_end = 0;

	for (int i = 0; i < N; i++) {
		if (meetings[i].first >= current_end) {
			current_end = meetings[i].second;
			count++;
		}
	}

	cout << count;
	return 0;
}

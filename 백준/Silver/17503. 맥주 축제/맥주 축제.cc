#include <iostream>
#include <vector>
#include <queue>	// priority_queue
#include <algorithm>	// sort()
using namespace std;

bool compare_level(pair<int, int> a, pair<int, int> b) {
	// 도수가 같으면 선호도가 높은 걸 먼저 배치
	if (a.second == b.second) {
		return a.first > b.first;
	}
	// 기본적으로 도수가 낮은 걸 먼저 배치
	return a.second < b.second;
}

int main() {
	/* 입력 */
	int N = 0, M = 0, K = 0;
	cin >> N >> M >> K;

	vector<pair<int, int>> beerList;	// <선호도, 도수> 쌍을 저장하는 벡터
	for (int i = 0; i < K; i++) {
		int preference = 0, level = 0;
		cin >> preference >> level;
		beerList.push_back(make_pair(preference, level));
	}
	sort(beerList.begin(), beerList.end(), compare_level);

	/* 맥주 선택: 그리디 */
	struct compare_preference {
		bool operator() (pair<int, int> a, pair<int, int> b) {
			// 선호도가 같으면 도수가 높은 게 먼저 빠지게 배치
			if (a.first == b.first) {
				return a.second < b.second;
			}
			// 기본적으로 선호도가 낮은 게 먼저 빠지게 배치
			return a.first > b.first;
		}
	};
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare_preference> selectedBeer;
	int sum = 0;
	int maxLevel = 0;

	for (int i = 0; i < K; i++) {
		/* 목표 개수를 채운 경우 선호도 만족 검사 */
		if (selectedBeer.size() == N) {
			// 만족도를 채웠는지 검사
			if (sum >= M) {
				break;
			}
			// 만족도 못 채웠으면 선호도가 가장 낮은 맥주 선택 취소
			else {
				sum -= selectedBeer.top().first;
				selectedBeer.pop();
			}
		}
		
		/* 목표 개수를 못 채운 경우 남은 맥주 중에 레벨 낮은 거 선택 */
		selectedBeer.push(beerList[i]);
		sum += beerList[i].first;
		// 선택된 맥주들 중 최대 레벨 찾기
		if (beerList[i].second > maxLevel) {
			maxLevel = beerList[i].second;
		}

		// 마지막까지 선호도 못 채운 경우 -1 출력하도록 설정
		if (i == K - 1 && sum < M) {
			maxLevel = -1;
		}
	}

	cout << maxLevel;

	return 0;
}

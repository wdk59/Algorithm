#include <iostream>
#include <vector>
using namespace std;

int M = 0;

vector<pair<int, int>> houses;		// 집들의 좌표 저장
vector<pair<int, int>> chickens;	// 치킨집들의 좌표 저장

vector<int> houseToChickens[100];
bool openChicken[13];	// 유지할 치킨집 선택

int minCityChickenDistance = 2147483647;	// 도시의 최소 치킨 거리

// 도시의 치킨 거리 연산 및 최솟값 비교
void calculateDistance() {
	/* 도시의 현재 치킨 거리 계산 */
	int nowCityChickenDistance = 0;

	for (int i = 0; i < houses.size(); i++) {
		int nowHouseChickenDistance = 2147483647;
		for (int j = 0; j < chickens.size(); j++) {
			if (openChicken[j]) {
				nowHouseChickenDistance = nowHouseChickenDistance > houseToChickens[i][j] ? houseToChickens[i][j] : nowHouseChickenDistance;
			}
		}
		nowCityChickenDistance += nowHouseChickenDistance;
	}

	minCityChickenDistance = minCityChickenDistance > nowCityChickenDistance ? nowCityChickenDistance : minCityChickenDistance;
}

void DFS_selectChicken(int idx, int depth) {
	// 치킨집을 모두 선택했을 때
	if (depth == M) {
		// 도시의 치킨 거리 연산 및 최솟값 비교
		calculateDistance();
	}

	// 조합: 현재 방문한 치킨집 이전의 치킨집을 방문하면 중복 선택하는 경우 발생
	for (int i = idx; i < chickens.size(); i++) {
		if (!openChicken[i]) {
			openChicken[i] = true;
			DFS_selectChicken(i + 1, depth + 1);
			openChicken[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	int N = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			cin >> tmp;
			if (tmp == 1)
				houses.push_back(make_pair(i, j));
			else if (tmp == 2)
				chickens.push_back(make_pair(i, j));
		}
	}

	/* 각 집의 치킨 거리 확인 */
	for (int i = 0; i < houses.size(); i++) {
		for (int j = 0; j < chickens.size(); j++) {
			houseToChickens[i].push_back(abs(houses[i].first - chickens[j].first) + abs(houses[i].second - chickens[j].second));
		}
	}

	DFS_selectChicken(0, 0);

	cout << minCityChickenDistance;;

	return 0;
}
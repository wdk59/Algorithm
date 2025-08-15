#include <iostream>
using namespace std;

int main() {
	int n = 0, k = 0;
	int pull = 0;

	cin >> n >> k;
	
	int* tab = new int[n];
	int* turn = new int[k];

	for (int i = 0; i < n; i++) {
		tab[i] = 0;
	}

	for (int i = 0; i < k; i++) {
		cin >> turn[i];
	}

	for (int i = 0; i < k; i++) {
		bool isPut = false;	// 이미 꽂혀있으면 1차 for문 넘겨야 함
		// 꽂혀 있는지 확인
		for (int j = 0; j < n; j++) {
			if (tab[j] == turn[i]) { isPut = true; break; }	// 꽂혀 있으니까 넘어감
		}
		if (isPut) { continue; }
		// 안 꽂혀 있음
		// 빈 자리 있는지 확인
		for (int j = 0; j < n; j++) {
			if (tab[j] == 0) {
				tab[j] = turn[i];
				isPut = true;
				break;	// 빈 자리 있으니까 꽂고 넘어감
			}
		}
		if (isPut) { continue; }
		// 빈 자리 없음: 하나 뽑아야 함
		// 꽂혀있는 것들 중 가장 나중에 다시 사용되는 것을 뽑는다.
		int targetPos = -1;	// 뽑을 위치
		int targetTaskTurn = 0;	// 가장 나중에 다시 사용되는 기기의 순서
		// 탭에 꽂혀있는 거 하나씩 검사
		for (int j = 0; j < n; j++) {
			int tmpTurn = 0;	// 현재 탭의 기기가 다시 사용되는 순서
			// 다음에 사용할 경우 찾기
			for (tmpTurn = i + 1; tmpTurn < k; tmpTurn++) {
				// 찾음
				if (turn[tmpTurn] == tab[j]) { break; }
				// 아직 못 찾으면 다음꺼 검사하게 넘어감
			}
			// 다시 사용되지 않음
			if (tmpTurn == k) {
				targetPos = j;
				targetTaskTurn = tmpTurn;
				break;
			}
			// 다시 사용될 예정: 현재 탭의 기기가 더 나중에 사용되면 target 바꿔주기
			if (targetTaskTurn < tmpTurn) {
				targetPos = j;
				targetTaskTurn = tmpTurn;
			}
		}
		tab[targetPos] = turn[i];
		pull++;
	}

	cout << pull;

	return 0;
}

#include<iostream>
using namespace std;

int main() {
	long long N = 0;
	cin >> N;
	
	// N이 0일 수도 있으니까 0부터 시작. 1로 시작해서 틀렸었음.
	long long cat = 0, cnt = 0;
	
	while (cat < N) {
		// 고양이 만들어야 하니까 횟수 증가시키기
		cnt++;

		/* 생성 */
		if (cat == 0) {
			cat++;
			continue;
		}

		/* 복제: 고양이 수만큼 복제하면 반복 끝내기 */

		// 복제해도 목표치에 도달 못 하는 경우: 계속 연산
		if (cat + cat < N) {
			cat += cat;
		}
		// 복제했을 때 목표치에 도달 가능한 경우에는 목표 달성했으므로 while문 탈출
		else {
			break;
		}
	}

	cout << cnt;

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/* 입력 */
	int R = 0, C = 0, A = 0, B = 0;
	cin >> R >> C;
	vector<string> quart(R, "");	// 좌상
	for (int i = 0; i < R; i++)
		cin >> quart[i];
	cin >> A >> B;
	A--; B--;

	/* 카드 만들기 */
	vector<string> card(quart);
	// 윗부분 만들기: 왼쪽 무늬를 오른쪽으로 복사
	for (int i = 0; i < R; i++)
		for (int j = C - 1; j >= 0; j--)
			card[i].push_back(card[i][j]);
	// 아랫부분 만들기
	for (int i = R - 1; i >= 0; i--)
		card.push_back(card[i]);
	// 에러 만들기
	card[A][B] = (card[A][B] == '.' ? '#' : '.');

	/* 출력 */
	for (int i = 0; i < R * 2; i++) {
		for (int j = 0; j < C * 2; j++)
			cout << card[i][j];
		cout << '\n';
	}

	return 0;
}

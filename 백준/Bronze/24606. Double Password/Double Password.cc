#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	string first = "", second = "";
	cin >> first >> second;

	/* 풀이 */
	int answer = 1, cnt = 0;
	for (int i = 0; i < 4; i++)
		cnt += (first[i] != second[i]);
	while (cnt--)
		answer *= 2;

	/* 출력 */
	cout << answer;

	return 0;
}

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;
	string S = "", X = "";
	int startIdx = 0;
	bool isSame = false;
	while (T--) {
		cin >> S;
		X = S;
		startIdx = 0;
		isSame = false;
		while (!isSame) {
			isSame = true;
			// 대칭 시작 지점 찾기 (뒤로 연결되니까 앞에서부터 범위 줄여나가기)
			// i: 뒤에서부터 검사할 인덱스 번호
			for (int i = 0; i + startIdx < S.size(); i++) {
				if (S[i + startIdx] != S[S.size() - i - 1]) {
					startIdx++;
					isSame = false;
					break;
				}
			}
		}
		// 대칭 시작 지점 앞에 있는 문자 뒤에 붙여주기
		for (int i = startIdx - 1; i >= 0; i--)
			X += S[i];

		cout << X << '\n';
	}

	return 0;
}

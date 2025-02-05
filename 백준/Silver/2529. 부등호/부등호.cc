#include <iostream>
#include <string>
using namespace std;

int k = 0;	// 부등호의 수
char sign[9] = "";

string minResult = "";
string maxResult = "";

bool visited[10] = { false, };

bool check(char op, int front, int back) {
	if (op == '<')
		return front < back;
	if (op == '>')
		return front > back;
	return true;
}

void DFS_find(int depth, string selectedNum) {
	/* 자리를 다 채운 경우 최솟값, 최대값 구분하기 */
	// 오름차순으로 탐색하기 때문에
	//   minResult가 비어 있으면 현재 발견한 수가 최솟값
	//   maxResult에 마지막으로 채워진 값이 최대값
	if (depth == k + 1) {
		if (minResult == "")
			minResult = selectedNum;
		else
			maxResult = selectedNum;
		return;
	}

	/* 결과값에 들어갈 숫자 선택하기 */
	for (int i = 0; i <= 9; i++) {
		// 이미 선택된 문자인 경우에는 뛰어넘기
		//if (selectedNum.find(i + '0') != string::npos)
		if (visited[i])
			continue;

		// 선택된 숫자가 없는 경우, 현재 숫자(i) 선택하기
		// 선택된 숫자가 있는 경우(OR), 부등호를 만족하면 다음 부등호 검사
		if (depth == 0 || check(sign[depth - 1], selectedNum[depth - 1] - '0', i)) {
			visited[i] = true;
			DFS_find(depth + 1, selectedNum + to_string(i));
			visited[i] = false;

		}
	}

	return;
}

int main() {
	cin >> k;

	for (int i = 0; i < k; i++)
		cin >> sign[i];

	DFS_find(0, "");

	cout << maxResult << "\n" << minResult;

	return 0;
}

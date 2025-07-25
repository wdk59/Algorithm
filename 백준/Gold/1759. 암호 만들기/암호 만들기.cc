#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> vec;

void dfs(int L, int C, int depth, int start, int a, int b, string tmp) {
	if (depth == L) {
		if (a >= 1 && b >= 2)
			cout << tmp << '\n';
		return;
	}

	for (int i = start; i < C; i++) {
		char ch = vec[i];
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			dfs(L, C, depth + 1, i + 1, a + 1, b, tmp + ch);
		else
			dfs(L, C, depth + 1, i + 1, a, b + 1, tmp + ch);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int L = 0, C = 0;
	cin >> L >> C;
	char ch = '\0';
	for (int i = 0; i < C; i++) {
		cin >> ch;
		vec.push_back(ch);
	}
	sort(vec.begin(), vec.end());

	dfs(L, C, 0, 0, 0, 0, "");

	return 0;
}
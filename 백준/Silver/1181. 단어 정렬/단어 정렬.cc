#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	// 길이가 같을 경우 사전순으로 정렬
	if (a.length() == b.length())
		return a < b;
	// 길이가 다를 경우 길이순으로 정렬
	else
		return a.length() < b.length();
}

int main() {
	vector<string> s;
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp = "";
		cin >> tmp;
		s.push_back(tmp);
	}

	sort(s.begin(), s.end(), compare);

	for (int i = 0; i < N; i++) {
		if (i != 0 && s[i] == s[i - 1]) {
			continue;
		}
		cout << s[i] << endl;
	}
	
	return 0;
}

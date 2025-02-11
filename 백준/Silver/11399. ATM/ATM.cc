#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N = 0;
	cin >> N;
	vector<int> p;
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		cin >> tmp;
		p.push_back(tmp);
	}
	sort(p.begin(), p.end());

	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			sum += p[j];
		}
	}

	cout << sum;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	cin >> n;

	vector<int> vec;
	for (int i = 0; i < n; i++) {
		vec.push_back(0);
		cin >> vec[i];
	}

	int v = 0;
	cin >> v;

	cout << count(vec.begin(), vec.end(), v);

	return 0;
}

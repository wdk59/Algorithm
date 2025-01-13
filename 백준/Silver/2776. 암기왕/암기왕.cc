#include <iostream>
#include <vector>
#include <algorithm>	// sort, binary_search

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int test = 0;
	cin >> test;

	for (int t = 0; t < test; t++) {
		int n = 0, m = 0;
		vector<int> note1;

		cin >> n;
		for (int i = 0; i < n; i++) {
			int a = 0;
			cin >> a;
			note1.push_back(a);
		}
		sort(note1.begin(), note1.end());
		cin >> m;
		for (int i = 0; i < m; i++) {
			int a = 0;
			cin >> a;
			cout << (binary_search(note1.begin(), note1.end(), a) ? 1 : 0) << "\n";
		}
	}

	return 0;
}
#include <iostream>
using namespace std;

void dp(int ap[15][15], long long* h, long long* k) {
	for (int i = *h + 1; i <= *k; i++) {
		ap[i][0] = 0;
		for (int j = 1; j <= 14; j++)
			ap[i][j] = ap[i - 1][j] + ap[i][j - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	long long k = 0, highest = 0;
	int apart[15][15];
	for (int i = 1; i <= 14; i++)
		apart[0][i] = i;
	
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		if (k > highest) {
			dp(apart, &highest, &k);
			highest = k;
		}
		cout << apart[k][n] << '\n';
	}

	return 0;
}

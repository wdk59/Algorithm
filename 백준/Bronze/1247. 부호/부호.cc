#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 3, N = 0, flow = 0;
	long long tmp = 0;
	while (t-- > 0) {
	__int128 sum = 0;
		sum = 0;
		flow = 0;
		cin >> N;
		while (N-- > 0) {
			cin >> tmp;
			sum += tmp;
		}
		
		if (sum > 0)
			cout << "+\n";
		else if (sum < 0)
			cout << "-\n";
		else
			cout << "0\n";
	}

	return 0;
}

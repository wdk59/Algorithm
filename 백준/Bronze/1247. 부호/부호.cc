#include <iostream>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 3, N = 0, flow = 0;
	long long sum = 0, tmp = 0;
	while (t-- > 0) {
		sum = 0;
		flow = 0;
		cin >> N;
		while (N-- > 0) {
			cin >> tmp;
			if (sum > 0 && tmp > 0 && sum > LLONG_MAX - tmp)
				flow++;
			else if (sum < 0 && tmp < 0 && sum < LLONG_MIN - tmp)
				flow--;
			sum += tmp;
		}
		
		if (flow > 0)
			cout << "+\n";
		else if (flow < 0)
			cout << "-\n";
		else if (sum > 0)
			cout << "+\n";
		else if (sum < 0)
			cout << "-\n";
		else
			cout << "0\n";
	}

	return 0;
}

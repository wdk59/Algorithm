#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n = 0, sum = 0;
	vector<int> multiple;
	while (true) {
		multiple = vector<int>();
		sum = 0;
		cin >> n;
		if (n == -1)
			return 0;

		for (int i = 1; i <= n / 2; i++) {
			if (n % i == 0) {
				multiple.push_back(i);
				sum += i;
			}
		}

		cout << n << ' ';
		if (sum == n) {
			cout << "= " << multiple[0];
			for (int i = 1; i < multiple.size(); i++)
				cout << " + " << multiple[i];
			cout << '\n';
		}
		else
			cout << "is NOT perfect.\n";
	}

	return 0;
}

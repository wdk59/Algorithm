#include <iostream>
#include <string>
using namespace std;

int main() {
	int N = 0;
	cin >> N;

	int num = 666;
	int cnt = 1;
	while (cnt < N) {
		num++;
		if (to_string(num).find("666") != string::npos) {
			cnt++;
		}
	}

	cout << num;

	return 0;
}

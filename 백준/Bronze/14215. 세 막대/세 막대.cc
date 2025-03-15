#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int length[3];
	cin >> length[0] >> length[1] >> length[2];
	sort(length, length + 3);
	if (length[0] + length[1] <= length[2] || length[1] + length[2] <= length[0] || length[0] + length[2] <= length[1])
		length[2] = length[0] + length[1] - 1;

	cout << length[0] + length[1] + length[2];

	return 0;
}

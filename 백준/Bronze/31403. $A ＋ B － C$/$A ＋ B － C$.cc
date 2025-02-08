#include <iostream>
#include <string>
using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	cout << a + b - c << endl;
	cout << stoi(to_string(a) + to_string(b)) - c;

	return 0;
}

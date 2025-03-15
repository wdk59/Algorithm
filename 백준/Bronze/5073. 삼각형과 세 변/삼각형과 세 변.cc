#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			return 0;

		if (a + b <= c || b + c <= a || a + c <= b)
			cout << "Invalid\n";
		else if (a == b && b == c && c == a)
			cout << "Equilateral\n";
		else if (a == b || b == c || a == c)
			cout << "Isosceles\n";
		else
			cout << "Scalene\n";

	}
	return 0;
}

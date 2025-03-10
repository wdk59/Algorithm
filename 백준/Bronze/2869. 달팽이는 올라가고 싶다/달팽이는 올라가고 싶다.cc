#include <iostream>
using namespace std;

int main() {
	int V = 0, A = 0, B = 0;
	cin >> A >> B >> V;

	cout << ((V - B) % (A - B) == 0 ? (V - B) / (A - B) : (V - B) / (A - B) + 1);

	return 0;
}

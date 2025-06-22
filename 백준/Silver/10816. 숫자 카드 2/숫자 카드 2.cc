#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num = 0, input = 0;
	unordered_map<int, int> m;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> input;
		m[input]++;
	}
	
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> input;
		cout << m[input] << ' ';
	}

	return 0;
}

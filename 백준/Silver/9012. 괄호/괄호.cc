#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string data = "";

	int num = 0, cnt = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> data;
		cnt = 0;
		for (int j = 0; j < data.size(); j++) {
			data[j] == '(' ? cnt++ : cnt--;
			if (cnt < 0)
				break;
		}
		cout << (cnt == 0 ? "YES" : "NO") << '\n';
	}
	

	return 0;
}

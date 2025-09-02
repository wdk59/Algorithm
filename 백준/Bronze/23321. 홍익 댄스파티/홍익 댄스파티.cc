#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string st[5];
	for (int i = 0; i < 5; i++)
		cin >> st[i];

	string ready = ".omln";
	string jumping = "owln.";
	string sit = "..oLn";

	string tmp = "";
	for (int i = 0; i < st[0].size(); i++) {
		tmp = "";
		for (int j = 0; j < 5; j++)
			tmp += st[j][i];
		if (tmp == ready)
			for (int j = 0; j < 5; j++)
				st[j][i] = jumping[j];
		else if (tmp == jumping)
			for (int j = 0; j < 5; j++)
				st[j][i] = ready[j];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < st[0].size(); j++)
			cout << st[i][j];
		cout << '\n';
	}
	
	return 0;
}

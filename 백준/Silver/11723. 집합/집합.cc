#include <iostream>
#include <set>
using namespace std;

void add(set<int>& S, int x) {
	S.insert(x);
}

void remove(set<int>& S, int x) {
	if (S.find(x) != S.end())
		S.erase(S.find(x));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M = 0, x = 0;
	string op = "";
	set<int> S;
	
	cin >> M;
	while (M-- > 0) {
		cin >> op;
		if (!(op == "all" || op == "empty"))
			cin >> x;
		
		if (op == "add")
			add(S, x);
		else if (op == "remove")
			remove(S, x);
		else if (op == "check")
			cout << (S.find(x) != S.end() ? 1 : 0) << '\n';
		else if (op == "toggle")
			S.find(x) != S.end() ? remove(S, x) : add(S, x);
		else if (op == "all")
			S = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,17, 18, 19, 20 };
		else if (op == "empty")
			S = set<int>();
	}

	return 0;
}

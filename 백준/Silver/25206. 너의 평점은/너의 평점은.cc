#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, float> grade = { {"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0},
		{"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0.0} };

	string sub, score;
	float credit = 0.0, sumMulti = 0.0, sumCredits = 0.0;

	for (int i = 0; i < 20; i++) {
		cin >> sub >> credit >> score;
		if (score == "P")
			continue;

		sumMulti += credit * grade[score];
		sumCredits += credit;
	}

	cout << sumMulti / sumCredits;

	return 0;
}

#include <iostream>
using namespace std;

int main() {
	int matrix[9][9], maxI = 0, maxJ = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] > matrix[maxI][maxJ]) {
				maxI = i;
				maxJ = j;
			}
		}
	}
	
	cout << matrix[maxI][maxJ] << '\n' << maxI + 1 << ' ' << maxJ + 1;

	return 0;
}

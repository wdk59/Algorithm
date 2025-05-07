#include <iostream>
#include <algorithm>
using namespace std;

bool findNum(int arr[], int num, int size) {
	int left = 0, right = size - 1;
	while (left <= right) {
		if (arr[(left + right) / 2] == num)
			return true;
		else if (arr[(left + right) / 2] > num)
			right = (left + right) / 2 - 1;
		else
			left = (left + right) / 2 + 1;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	int arr[100000];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	cin >> M;
	int tmp = 0;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		cout << findNum(arr, tmp, N) << '\n';
	}

	return 0;
}

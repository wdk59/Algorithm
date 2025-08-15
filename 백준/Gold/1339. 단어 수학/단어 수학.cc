#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* 입력 */
	int N = 0;
	cin >> N;
	vector<string> words(N, "");
	for (int i = 0; i < N; i++)
		cin >> words[i];

	/* 가중치 부여 */
	unordered_map<char, int> weight;
	for (string& word : words)
		// 모든 단어에서의 자리를 누적해야 함
		for (int i = 0; i < word.size(); i++)
			//weight[word[i]] = word.size() - i;
			weight[word[i]] += pow(10, word.size() - i - 1);
	// 가중치 기준 내림차순으로 정렬
	vector<pair<char, int>> weightVec(weight.begin(), weight.end());
	sort(weightVec.begin(), weightVec.end(), [](pair<char, int> a, pair<char, int> b) { return a.second > b.second; });

	/* 정수 할당 */
	int num = 9;
	unordered_map<char, int> alToNum;
	for (pair<char, int> ch : weightVec)
		alToNum[ch.first] = num--;

	/* [ 단어 -> 숫자 ] 변환 및 합산 */
	int sum = 0;
	for (string& word : words) {
		for (char& ch : word)
			ch = alToNum[ch] + '0';
		sum += stoi(word);
	}

	/* 출력 */
	cout << sum;

	return 0;
}
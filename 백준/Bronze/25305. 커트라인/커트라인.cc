#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool descending(int a, int b) {
    return b < a;
}

int main() {
    int N = 0, k = 0;
    vector<int> score;
    int tmp = 0;
    cin >> N >> k;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        score.push_back(tmp);
    }
    sort(score.begin(), score.end(), descending);
    cout << score[k - 1];

    return 0;
}

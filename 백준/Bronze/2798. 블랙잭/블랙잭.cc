#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 0, M = 0, result = 0;
    vector<int> cards(N);
    int tmp = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        cards.push_back(tmp);
    }

    for (int i = 0; i < N - 2; i++) {
        if (cards[i] >= M)
            break;
        for (int j = i + 1; j < N - 1; j++) {
            if (cards[j] >= M)
                break;
            for (int k = j + 1; k < N; k++) {
                if (cards[k] >= M)
                    break;
                tmp = cards[i] + cards[j] + cards[k];
                if (tmp <= M && tmp > result)
                    result = tmp;
            }
        }
    }

    cout << result;

    return 0;
}
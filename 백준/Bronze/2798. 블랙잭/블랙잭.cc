#include <iostream>
using namespace std;

int main() {
    int N = 0, M = 0, result = 0;
    int cards[100];

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> cards[i];

    int tmp = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                tmp = cards[i] + cards[j] + cards[k];
                if (tmp <= M && tmp > result)
                    result = tmp;
            }
        }
    }

    cout << result;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N = 0, tmp = 0;
    int num[10001] = { 0, };
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        num[tmp]++;
    }

    for (int i = 1; i < 10001; i++) {
        if (num[i] != 0) {
            for (int j = 0; j < num[i]; j++)
                cout << i << '\n';
        }
    }

    return 0;
}

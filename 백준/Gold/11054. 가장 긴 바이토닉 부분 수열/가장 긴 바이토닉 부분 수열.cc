#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> A(1001, 0);
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<int> dpGreater(1001, 0), dpLess(1001, 0);
    dpGreater[0] = 1;
    dpLess[n - 1] = 1;

    for (int i = 1; i < n; i++) {
        int maxGreater = 1, maxLess = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j])
                maxGreater = max(maxGreater, dpGreater[j] + 1);
            if (A[n - 1 - i] > A[n - 1 - j])
                maxLess = max(maxLess, dpLess[n - 1 - j] + 1);
        }
        dpGreater[i] = maxGreater;
        dpLess[n - 1 - i] = maxLess;
    }

    int answer = 1;
    for (int i = 0; i < n; i++)
        answer = max(answer, dpGreater[i] + dpLess[i]);
    cout << answer - 1; // 기본 원소 중복 제외

    return 0;
}

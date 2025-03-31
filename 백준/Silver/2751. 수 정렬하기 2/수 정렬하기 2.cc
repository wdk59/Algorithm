#include <iostream>
#include <algorithm>
using namespace std;

int num[1000000] = { 0, };
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0, tmp = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];

    sort(num, num + N);

    for (int i = 0; i < N; i++)
        cout << num[i] << '\n';

    return 0;
}

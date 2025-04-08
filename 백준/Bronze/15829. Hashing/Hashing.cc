#include <iostream>
using namespace std;

long long longPow(int base, int exp, long long mod) {
    long long result = 1;
    for (int i = exp; i > 0; i--)
        result = result * base % mod;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M = 1234567891;

    int L = 0;
    cin >> L;
    string str = "";
    cin >> str;

    long long result = 0;
    for (int i = 0; i < L; i++)
        result += (long long)(str[i] - 'a' + 1) * longPow(31, i, M) % M;

    cout << result % M;

    return 0;
}

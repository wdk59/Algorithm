#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0, t = 0, p = 0, sumT = 0;
    cin >> n;
    int sizes[6] = { 0, };
    for (int i = 0; i < 6; i++)
        cin >> sizes[i];
    cin >> t >> p;
    
    for (int i = 0; i < 6; i++) {
        sumT += sizes[i] / t;
        if (sizes[i] % t != 0)
            sumT++;
    }

    cout << sumT << '\n';
    cout << n / p << ' ' << n % p;

    return 0;
}

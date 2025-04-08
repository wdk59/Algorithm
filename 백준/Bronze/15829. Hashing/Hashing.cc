#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L = 0;
    cin >> L;
    string str = "";
    cin >> str;

    int result = 0;
    for (int i = 0; i < L; i++)
        result += (str[i] - 'a' + 1) * pow(31, i);

    cout << result;

    return 0;
}

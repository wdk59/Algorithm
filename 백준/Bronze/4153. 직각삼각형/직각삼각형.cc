#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a = 0, b = 0, c = 0, tmp = 0;
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            return 0;

        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        if (b > c) {
            tmp = b;
            b = c;
            c = tmp;
        }

        cout << (a * a + b * b == c * c ? "right\n" : "wrong\n");
    }

    return 0;
}

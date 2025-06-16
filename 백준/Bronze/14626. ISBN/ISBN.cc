#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string ISBN = "";
    cin >> ISBN;
    
    int sum = 0, mul = 0;
    for (int i = 0; i < 13; i++) {
        if (isdigit(ISBN[i])) {
            if (i % 2 == 0)
                sum += (ISBN[i] - '0');
            else
                sum += (ISBN[i] - '0') * 3;
        }
        else {
            mul = (i % 2 == 0 ? 1 : 3);
        }
    }

    int result = 0;
    for (result = 0; result < 10; result++) {
        if ((sum + result * mul) % 10 == 0)
            break;
    }
    
    cout << result;

    return 0;
}

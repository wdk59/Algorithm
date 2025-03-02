#include <iostream>
using namespace std;

int main() {
    int T = 0;
    cin >> T;
    string str;
    for (int i = 0; i < T; i++) {
        cin >> str;
        cout << str[0] << str[str.size() - 1] << '\n';
    }
    
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N = 0, result = 0, tmp = 0;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        tmp = 0;
        for (char c: to_string(i))
            tmp += (c - '0');
        if (tmp + i == N) {
            result = i;
            break;
        }
    }
    cout << result;
}
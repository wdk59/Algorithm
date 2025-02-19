#include <iostream>
using namespace std;

int main() {
    bool students[30];
    for (int i = 0; i < 30; i++) {
        students[i] = false;
    }
    
    int tmp = 0;
    for (int i = 0; i < 30; i++) {
        cin >> tmp;
        students[tmp - 1] = true;
    }
    
    for (int i = 0; i < 30; i++) {
        if (!students[i]) {
            cout << i + 1 << '\n';
        }
    }
    
    return 0;
}
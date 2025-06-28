#include <iostream>
#include <stack>
using namespace std;

int priority(char c) {
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = "";
    cin >> str;
    
    stack<char> op;
    for (char ch: str) {
        if (isalpha(ch)) {
            cout << ch;
        }
        else {
            if (ch == '(') {
                op.push(ch);
            }
            else {
                while (!op.empty() && priority(ch) <= priority(op.top())) {
                    if (op.top() == '(') {
                        op.pop();
                        break;
                    }

                    cout << op.top();
                    op.pop();
                }

                if (ch != ')')
                    op.push(ch);
            }
        }
    }

    while (!op.empty()) {
        cout << op.top();
        op.pop();
    }

    return 0;
}

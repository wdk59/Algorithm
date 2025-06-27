#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> before;
    
    for (int i = 0; i < s.length(); i++) {
        if (before.empty() || before.top() != s[i]) {
            before.push(s[i]);
        } else {
            before.pop();
        }
    }
    answer = before.empty() ? 1 : 0;

    return answer;
}
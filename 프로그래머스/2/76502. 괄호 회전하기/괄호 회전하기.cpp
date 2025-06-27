#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> st;

    int re = s.length(), j = 0;
    for (int i = 0; i < re; i++) {
        st = stack<char>();
        for (j = 0; j < s.length(); j++) {
            if (s[j] == '[' || s[j] == '{' || s[j] == '(')
                st.push(s[j]);
            else if (!st.empty() && ((st.top() == '[' && s[j] == ']') || (st.top() == '{' && s[j] == '}') || (st.top() == '(' && s[j] == ')')))
                st.pop();
            else
                break;
        }
        if (st.empty() && j == s.length())
            answer++;

        s += s[0];
        s.erase(0, 1);
    }

    return answer;
}
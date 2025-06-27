#include <string>
#include <stack>

using namespace std;

bool isCorrect(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            st.push(s[i]);
        else if (st.empty() || !((st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}') || (st.top() == '(' && s[i] == ')')))
            return false;
        else
            st.pop();
    }

    return st.empty();
}

int solution(string s) {
    int answer = 0;

    int re = s.length(), j = 0;
    for (int i = 0; i < re; i++) {

        if (isCorrect(s))
            answer++;

        s += s[0];
        s.erase(0, 1);
    }

    return answer;
}
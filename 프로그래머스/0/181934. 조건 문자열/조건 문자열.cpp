#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    int answer = 0;
    
    if (n == m) {
        answer = eq == "=" ? 1 : 0;
    } else if (n < m) {
        answer = ineq == "<" ? 1 : 0;
    } else if ( n > m) {
        answer = ineq == ">" ? 1 : 0;
    }
    
    return answer;
}
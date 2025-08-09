#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    unordered_set<int> dp[9];
    int tmp = N;    // N, NN, NNN, ...
    for (int i = 1; i < 9; i++) {
        dp[i].insert(tmp);
        tmp *= 10;  tmp += N;
    }
    
    // N 사용 횟수 8보다 커지면 무시
    for (int i = 2; i < 9; i++) {
        for (int j = 1; j < i; j++) {
            for (int left: dp[j]) {
                for (int right: dp[i - j]) {
                    dp[i].insert(left + right);
                    dp[i].insert(left - right);
                    dp[i].insert(left * right);
                    if (right != 0)
                        dp[i].insert(left / right);
                }
            }
        }
    }
    
    for (int i = 1; i < 9; i++)
        if (dp[i].find(number) != dp[i].end())
            return i;
    
    return -1;
}
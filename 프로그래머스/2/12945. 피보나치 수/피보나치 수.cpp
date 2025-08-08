#include <iostream>
#include <vector>

using namespace std;

int fib(int n, vector<int>& dp) {
    if (dp[n] != 0)
        return dp[n];
    
    dp[n] = (fib(n - 1, dp) + fib(n - 2, dp)) % 1234567;
    return dp[n];
}

int solution(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = dp[2] = 1;
    return fib(n, dp);
}
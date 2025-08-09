#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int mod = 1000000007;
    
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = 1;   // 집
    
    // 침수 지역 표시
    for (int i = 0; i < puddles.size(); i++)
        dp[puddles[i][0] - 1][puddles[i][1] - 1] = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == - 1) {
                if (i == 0 && j == 0)
                    continue;   // 집은 지나가면 안 되지
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] % mod;
                else if (j == 0)
                    dp [i][j] = dp[i - 1][j] % mod;
                else
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
            }
        }
    }
    
    return dp[m - 1][n - 1];
}
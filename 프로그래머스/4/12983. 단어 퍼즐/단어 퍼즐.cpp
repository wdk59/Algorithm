#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<string> strs, string t)
{
    const int INF = 20001;
    int answer = 0;

    vector<int> dp(t.size() + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < t.size(); i++) {
        if (dp[i] == INF)
            continue;
        
        for (int j = 0; j < strs.size(); j++) {
            if (i + strs[j].size() > t.size())
                continue;
            
            bool flag = true;
            for (int k = 0; k < strs[j].size(); k++) {
                if (t[i + k] != strs[j][k]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                dp[i + strs[j].size()] = min(dp[i + strs[j].size()], dp[i] + 1);
        }
    }

    return dp[t.size()] == INF ? -1 : dp[t.size()];
}
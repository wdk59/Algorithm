#include <string>
#include <vector>
using namespace std;

int solution(vector<string> strs, string t)
{
    const int INF = 20001;
    int answer = 0;

    vector<int> dp(t.size() + 1, INF);
    dp[0] = 0; // 빈 문자열은 0개의 조각으로 만들 수 있음

    // i: 현재까지 만들어진 문자열의 길이
    for (int i = 0; i < t.size(); i++) {
        // i번째까지 문자열을 만들 수 없으면 건너뜀
        if (dp[i] == INF)
            continue;

        // 모든 조각 확인
        for (int j = 0; j < strs.size(); j++) {
            // 범위 확인
            if (i + strs[j].size() > t.size())
                continue;

            // 일치하는지 직접 한 글자씩 비교 (substr 시간초과 발생)
            bool flag = true;
            for (int k = 0; k < strs[j].size(); k++) {
                if (t[i + k] != strs[j][k]) {
                    flag = false; // 하나라도 다르면 실패
                    break;
                }
            }

            // 일치하는 조각이면, 해당 조각을 붙여서 새 위치의 최소 횟수 갱신
            if (flag)
                dp[i + strs[j].size()] = min(dp[i + strs[j].size()], dp[i] + 1);
        }
    }

    // 최종적으로 t 전체를 만들 수 없다면 -1 반환, 가능하면 최소 횟수 반환
    return dp[t.size()] == INF ? -1 : dp[t.size()];
}

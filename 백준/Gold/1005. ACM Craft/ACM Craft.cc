// 위상정렬
// https://velog.io/@min-ji99/%EB%B0%B1%EC%A4%801516-%EA%B2%8C%EC%9E%84%EA%B0%9C%EB%B0%9C

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        /* 입력 */

        int N = 0, K = 0;
        cin >> N >> K; // 건물 수, 규칙 수

        vector<int> buildTime(N + 1, 0);   // 각 건물 건설 시간
        vector<int> indegree(N + 1, 0); // 각 건물 진입 차수
        vector<int> dp(N + 1, 0);          // 각 건물까지 걸리는 최소 시간
        vector<vector<int>> v(N + 1);   // 건물 간 의존 관계
        queue<int> q;

        // 건설 시간 입력
        for (int i = 1; i <= N; i++)
            cin >> buildTime[i];

        // 관계 입력
        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);  // a를 지은 후에 b를 지을 수 있음
            indegree[b]++;
        }

        /* 위상정렬 + DP */
        int W;
        cin >> W; // 목표 건물 번호

        // 선행 건물이 없는 건물부터 큐에 넣기
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : v[cur]) {
                dp[next] = max(dp[next], dp[cur] + buildTime[cur]);

                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        /* 출력 */
        // 목표 건물까지 걸리는 최소 시간 = dp[W] + 자기 자신 짓는 시간
        cout << dp[W] + buildTime[W] << '\n';
    }

    return 0;
}

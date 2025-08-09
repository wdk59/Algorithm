#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> buildTime(N + 1);
    vector<int> indegree(N + 1, 0);
    vector<int> answer(N + 1);
    vector<vector<int>> v(N + 1);
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        int t;
        cin >> t;
        buildTime[i] = t;
        while (true)
        {
            int num;
            cin >> num;
            if (num == -1) break;
            v[num].push_back(i);
            indegree[i]++;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : v[cur])
        {
            answer[next] = max(answer[next], answer[cur] + buildTime[cur]);

            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << answer[i] + buildTime[i] << '\n';
    }
    return 0;
}

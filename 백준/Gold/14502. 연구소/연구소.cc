#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 10

vector<vector<int>> map;
vector<vector<int>> tmpM;
vector<vector<bool>> visited;

// 상하좌우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };


int N = 0, M = 0, cnt = 3, answer = 0;

void BFS()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            tmpM[i][j] = map[i][j];


    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (tmpM[i][j] == 2)
            {
                queue<pair<int, int>> q;

                q.push({ i, j });
                visited[i][j] = true;

                while (!q.empty())
                {
                    int curY = q.front().first;
                    int curX = q.front().second;
                    q.pop();

                    for (int next = 0; next < 4; next++)
                    {
                        int nextY = curY + dy[next];
                        int nextX = curX + dx[next];

                        // 범위 및 방문 여부 확인
                        if (nextY >= 1 && nextY <= N && nextX >= 1 && nextX <= M) {
                            if (!visited[nextY][nextX] && tmpM[nextY][nextX] == 0)
                            {
                                q.push({ nextY, nextX });
                                visited[nextY][nextX] = true;
                                tmpM[nextY][nextX] = 2;
                            }
                        }
                    }
                }
            }
        }
    }

    visited = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));

    int temp = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (tmpM[i][j] == 0)
                temp++;
        }
    }

    if (temp > answer)
        answer = temp;
}

void search()
{
    if (cnt == 0)
        return BFS();

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (map[i][j] == 0)
            {
                cnt--;
                map[i][j] = 1;
                search();
                cnt++;
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> N >> M;
    visited = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));
    map = vector<vector<int>>(N + 1, vector<int>(M + 1, -1));
    tmpM = vector<vector<int>>(N + 1, vector<int>(M + 1, -1));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> map[i][j];

    // 탐색
    search();

    // 출력
    cout << answer << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct NODE {
    int x, y;
    int wallBroken;
    int dist;
};

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j) {
            map[i][j] = row[j] - '0';
        }
    }

    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(K + 1, false)));

    queue<NODE> q;
    q.push({ 0, 0, 0, 1 });
    visited[0][0][0] = true;

    while (!q.empty()) {
        NODE now = q.front();
        q.pop();

        if (now.x == N - 1 && now.y == M - 1) {
            cout << now.dist << '\n';
            return 0;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            // 벽이 아닌 경우
            if (map[nx][ny] == 0 && !visited[nx][ny][now.wallBroken]) {
                visited[nx][ny][now.wallBroken] = true;
                q.push({ nx, ny, now.wallBroken, now.dist + 1 });
            }

            // 벽이지만 부술 수 있는 경우
            if (map[nx][ny] == 1 && now.wallBroken < K && !visited[nx][ny][now.wallBroken + 1]) {
                visited[nx][ny][now.wallBroken + 1] = true;
                q.push({ nx, ny, now.wallBroken + 1, now.dist + 1 });
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
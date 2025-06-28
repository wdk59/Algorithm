// 다시 풀어보기. Dequqe를 제대로 못 씀

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0, 1, 0, -1 }; // L, D 회전에 따라 방향 순서
int dy[4] = { 1, 0, -1, 0 }; // 우, 하, 좌, 상

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<bool>> apple(n, vector<bool>(n, 0));
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        apple[r - 1][c - 1] = true;
    }

    int l;
    cin >> l;
    queue<pair<int, char>> cmd;
    for (int i = 0; i < l; i++) {
        int t;
        char d;
        cin >> t >> d;
        cmd.push({ t, d });
    }

    queue<pair<int, int>> snake;
    snake.push({ 0, 0 });
    vector<vector<bool>> isSnake(n, vector<bool>(n, false));
    isSnake[0][0] = true;

    int time = 0;
    int dir = 0;

    while (true) {
        time++;
        int nx = snake.back().first + dx[dir];
        int ny = snake.back().second + dy[dir];

        // 벽 충돌
        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            break;
        // 자기 몸과 충돌
        if (isSnake[nx][ny])
            break;

        // 이동
        snake.push({ nx, ny });
        isSnake[nx][ny] = true;

        // 사과 없으면 꼬리 제거
        if (!apple[nx][ny]) {
            pair<int, int> tail = snake.front();
            isSnake[tail.first][tail.second] = false;
            snake.pop();
        }
        else {
            apple[nx][ny] = false;
        }

        // 방향 전환
        if (!cmd.empty() && time == cmd.front().first) {
            if (cmd.front().second == 'D')
                dir = (dir + 1) % 4;
            else
                dir = (dir + 3) % 4;
            cmd.pop();
        }
    }

    cout << time;
    return 0;
}

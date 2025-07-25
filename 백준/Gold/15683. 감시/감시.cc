#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[8][8];
vector<pair<int, int>> cctv;
int answer = 2147483647;

// 우상좌하: CCTV 1번이 오른쪽이라서 우상좌하 순서로 설정
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

void check(int x, int y, int dir) {
    dir %= 4;
    while (true) {
        x += dx[dir];
        y += dy[dir];

        if (x < 0 || y < 0 || x >= N || y >= M || arr[x][y] == 6)
            return;

        if (arr[x][y] != 0)
            continue;

        arr[x][y] = -1;
    }
}

void dfs(int num) {
    // 카메라 설치 끝날 때마다 answer 갱신
    if (num == cctv.size()) {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (!arr[i][j]) cnt++;

        answer = min(answer, cnt);
        return;
    }

    int x = cctv[num].first;
    int y = cctv[num].second;
    int tmp[9][9];

    // 카메라 돌려가며 설치해보기
    for (int dir = 0; dir < 4; dir++) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                tmp[i][j] = arr[i][j];

        if (arr[x][y] == 1)
            check(x, y, dir);
        else if (arr[x][y] == 2) {
            check(x, y, dir);
            check(x, y, dir + 2);
        }
        else if (arr[x][y] == 3) {
            check(x, y, dir);
            check(x, y, dir + 1);
        }
        else if (arr[x][y] == 4) {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
        }
        else if (arr[x][y] == 5) {
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        // DFS: 다음 카메라 설치
        dfs(num + 1);

        // 카메라 다시 없애기
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                arr[i][j] = tmp[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0 && arr[i][j] != 6)
                cctv.push_back({ i, j });
        }
    }

    dfs(0);
    cout << answer << '\n';

    return 0;
}
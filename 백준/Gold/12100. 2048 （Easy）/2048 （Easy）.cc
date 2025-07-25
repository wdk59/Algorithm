#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0, answer = 0;
vector<vector<int>> map;

void move(int dir) {
    queue<int> q;
    // 0: 상
    if (dir == 0) {
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                if (map[i][j] != 0)
                    q.push(map[i][j]);
                map[i][j] = 0;
            }
            int idx = 0;
            while (!q.empty()) {
                int value = q.front();
                q.pop();
                // idx 번째 칸이 0인 경우: 큐 front 입력
                if (map[idx][j] == 0)
                    map[idx][j] = value;
                // idx번째 칸이 큐 front와 같은 값인 경우: 합치기
                else if (map[idx][j] == value) {
                    map[idx][j] *= 2;
                    idx++;
                }
                // 0 도 아니고 값이 다른 경우: 다음 칸에 큐 front 입력
                else {
                    idx++;
                    map[idx][j] = value;
                }
            }
        }
    }
    // 1: 하
    else if (dir == 1) {
        for (int j = 0; j < N; j++) {
            for (int i = N - 1; i >= 0; i--) {
                if (map[i][j] != 0)
                    q.push(map[i][j]);
                map[i][j] = 0;
            }
            int idx = N - 1;
            while (!q.empty()) {
                int value = q.front();
                q.pop();
                // idx 번째 칸이 0인 경우: 큐 front 입력
                if (map[idx][j] == 0)
                    map[idx][j] = value;
                // idx번째 칸이 큐 front와 같은 값인 경우: 합치기
                else if (map[idx][j] == value) {
                    map[idx][j] *= 2;
                    idx--;
                }
                // 0 도 아니고 값이 다른 경우: 다음 칸에 큐 front 입력
                else {
                    idx--;
                    map[idx][j] = value;
                }
            }
        }
    }
    // 2: 좌
    else if (dir == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] != 0)
                    q.push(map[i][j]);
                map[i][j] = 0;
            }
            int idx = 0;
            while (!q.empty()) {
                int value = q.front();
                q.pop();
                // idx 번째 칸이 0인 경우: 큐 front 입력
                if (map[i][idx] == 0)
                    map[i][idx] = value;
                // idx번째 칸이 큐 front와 같은 값인 경우: 합치기
                else if (map[i][idx] == value) {
                    map[i][idx] *= 2;
                    idx++;
                }
                // 0 도 아니고 값이 다른 경우: 다음 칸에 큐 front 입력
                else {
                    idx++;
                    map[i][idx] = value;
                }
            }
        }
    }
    // 3: 우
    else {
        for (int i = 0; i < N; i++) {
            for (int j = N - 1; j >= 0; j--) {
                if (map[i][j] != 0)
                    q.push(map[i][j]);
                map[i][j] = 0;
            }
            int idx = N - 1;
            while (!q.empty()) {
                int value = q.front();
                q.pop();
                // idx 번째 칸이 0인 경우: 큐 front 입력
                if (map[i][idx] == 0)
                    map[i][idx] = value;
                // idx번째 칸이 큐 front와 같은 값인 경우: 합치기
                else if (map[i][idx] == value) {
                    map[i][idx] *= 2;
                    idx--;
                }
                // 0 도 아니고 값이 다른 경우: 다음 칸에 큐 front 입력
                else {
                    idx--;
                    map[i][idx] = value;
                }
            }
        }
    }
}


void dfs(int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                answer = max(answer, map[i][j]);
            }
        }
        return;
    }

    // 현재 상태 저장
    vector<vector<int>> origin = map;

    for (int i = 0; i < 4; i++) {
        move(i);
        dfs(cnt + 1);

        // 원상복구
        map = origin;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> N;
    map = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    // 시뮬레이션
    dfs(0);

    // 출력
    cout << answer;

    return 0;
}
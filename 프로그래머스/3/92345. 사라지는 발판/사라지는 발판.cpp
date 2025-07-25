#include <string>
#include <vector>

using namespace std;

// 상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

// curx, cury: 현재 플레이어 좌표 / opx, opy: 상대 플레이어 좌표
int dfs(int& n, int& m, vector<vector<bool>>& visited, vector<vector<int>>& canGo, int curx, int cury, int opx, int opy) {
    if (visited[curx][cury])
        return 0;
    
    int now = 0;    // 지금 턴 수
    for (int dir = 0; dir < 4; dir++) {
        int nx = curx + dx[dir];
        int ny = cury + dy[dir];
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || !canGo[nx][ny])
            continue;
        
        visited[curx][cury] = true;
        int val = dfs(n, m, visited, canGo, opx, opy, nx, ny) + 1;  // 이동 후 턴 수
        
        if (now % 2 == 0 && val % 2 == 1)
            now = val;
        else if (now % 2 == 0 && val % 2 == 0)
            now = max(now, val);    // 최대한 늦게 지기
        else if (now % 2 == 1 && val % 2 == 1)
            now = min(now, val);    // 최대한 빨리 이기기
        
        visited[curx][cury] = false;
    }
    
    return now;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> canGo = board;
    
    
    return dfs(n, m, visited, canGo, aloc[0], aloc[1], bloc[0], bloc[1]);
}
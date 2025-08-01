#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 설치 가능한지 검사
bool canInstall(int x, int y, int a, vector<vector<vector<bool>>>& board) {
    if (a == 0) { // 기둥
        return y == 0 || board[x][y - 1][0] || board[x][y][1] || (x > 0 && board[x - 1][y][1]);
    } else { // 보
        return (y > 0 && (board[x][y - 1][0] || board[x + 1][y - 1][0])) ||
               (x > 0 && board[x - 1][y][1] && board[x + 1][y][1]);
    }
}

// 현재 설치된 모든 구조물이 조건 만족하는지 확인
bool isValid(int n, vector<vector<vector<bool>>>& board) {
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            for (int a = 0; a <= 1; a++) {
                if (board[x][y][a] && !canInstall(x, y, a, board))
                    return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    // { x, y, {기둥, 보} }
    vector<vector<vector<bool>>> board(n + 1, vector<vector<bool>>(n + 1, vector<bool>(2, false)));
    
    for (vector<int> work : build_frame) {
        int x = work[0], y = work[1], a = work[2], b = work[3];

        if (b == 1) { // 설치
            board[x][y][a] = true;
            if (!canInstall(x, y, a, board))    // 조건 불만족 시 설치 취소
                board[x][y][a] = false;
        } else { // 삭제
            board[x][y][a] = false;
            if (!isValid(n, board)) // 전체 구조물 유효성 검사
                board[x][y][a] = true; // 되돌림
        }
    }

    vector<vector<int>> answer;
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            for (int a = 0; a <= 1; a++) {
                if (board[x][y][a])
                    answer.push_back({x, y, a});
            }
        }
    }

    sort(answer.begin(), answer.end()); // x, y, a 순 정렬
    return answer;
}

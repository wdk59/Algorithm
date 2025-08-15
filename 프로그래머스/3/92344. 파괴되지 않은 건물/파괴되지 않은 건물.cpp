#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    /* 스킬 누적 */
    int diff = 0;
    vector<vector<int>> diffBoard(board.size(), vector<int>(board[0].size(), 0));
    for (vector<int> sk: skill) {
        diff = (sk[0] == 1 ? -sk[5] : sk[5]);
        
        // 시작 위치
        diffBoard[sk[1]][sk[2]] += diff;
        // 세로 끝
        if (sk[3] < board.size() - 1)
            diffBoard[sk[3] + 1][sk[2]] -= diff;
        // 가로 끝
        if (sk[4] < board[0].size() - 1)
            diffBoard[sk[1]][sk[4] + 1] -= diff;
        // 우하단
        if (sk[3] < board.size() - 1 && sk[4] < board[0].size() - 1)
            diffBoard[sk[3] + 1][sk[4] + 1] += diff;
    }
    
    /* 남은 건물 수 세기 */
    // diffBoard 구하기
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            // 스킬 누적 적용
            // 합: 좌
            if (i > 0)
                diffBoard[i][j] += diffBoard[i - 1][j];
            // 합: 상
            if (j > 0)
                diffBoard[i][j] += diffBoard[i][j - 1];
            // 차: 좌상(교집)
            if (i > 0 && j > 0)
                diffBoard[i][j] -= diffBoard[i - 1][j - 1];
        }
    }
    
    // diffBoard 적용
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            board[i][j] += diffBoard[i][j];
            
            // 생존?
            if (board[i][j] > 0)
                answer++;
        }
    }
    
    return answer;
}
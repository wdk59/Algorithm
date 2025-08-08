#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    for (int i = 0; i < board.size(); i++)
        if (board[i][0] == 1)
            answer = 1;
    for (int j = 0; j < board[0].size(); j++)
        if (board[0][j] == 1)
            answer = 1;

    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[0].size(); j++) {
            if (board[i][j] != 0) {
                board[i][j] = min({board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]}) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> bucket;
    
    for (int i: moves) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][i - 1] != 0) {
                if (bucket.empty() || bucket.top() != board[j][i - 1]) {
                    bucket.push(board[j][i - 1]);
                }
                else {
                    bucket.pop();
                    answer += 2;
                }
                board[j][i - 1] = 0;
                break;
            }
        }
    }
    
    return answer;
}

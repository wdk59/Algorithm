#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer(2, 0);
    
    for (string dir: keyinput) {
        if (dir == "up" && answer[1] < board[1] / 2)
            answer[1]++;
        else if (dir == "down" && answer[1] > -(board[1] / 2))
            answer[1]--;
        else if (dir == "left" && answer[0] > -(board[0] / 2))
            answer[0]--;
        else if (dir == "right" && answer[0] < board[0] / 2)
            answer[0]++;
    }
    
    return answer;
}
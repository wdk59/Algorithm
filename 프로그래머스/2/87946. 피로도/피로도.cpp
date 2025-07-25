#include <vector>

using namespace std;

void dfs(vector<vector<int>>& dungeons, int cnt, int& answer, int k, vector<bool>& visited) {
    if (answer < cnt)
        answer = cnt;
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && dungeons[i][0] <= k) {
            visited[i] = true;
            dfs(dungeons, cnt + 1, answer, k - dungeons[i][1], visited);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visited(dungeons.size(), false);
    
    dfs(dungeons, 0, answer, k, visited);
    
    return answer;
}
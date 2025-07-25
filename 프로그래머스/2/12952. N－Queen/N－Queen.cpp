#include <string>
#include <vector>

using namespace std;

void dfs(int& n, int depth, int& answer, vector<int>& row) {
    if (depth == n) {
        answer++;   // 끝까지 걸린 거 없음
        return;
    }
    
    for (int i = 0; i < n; i++) {
        row[depth] = i;   // Q 배치
        // 규칙 검사
        int isValid = true;
        for (int j = 0; j < depth; j++)
            if (row[depth] == row[j] || abs(row[depth] - row[j]) == abs(depth - j))
                isValid = false;
        if (isValid)
            dfs(n, depth + 1, answer, row);
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> row(n, 0);    // 한 행에 하나만 배치 (인덱스: 배치된 행 번호, 값: 배치된 열 번호)
    
    dfs(n, 0, answer, row);
    
    
    return answer;
}
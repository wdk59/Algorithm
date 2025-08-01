#include <iostream>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    string newName(name.size(), 'A');
    
    // 현재 글자 바꿔주기
    for (int i = 0; i < name.size(); i++) {
        int disA = name[i] - 'A';
        answer += disA < 13 ? disA : 26 - disA;
    }
    
    // 이동 횟수 최소화
    int minMove = name.size() - 1;  // 기본: 오른쪽으로 한 칸씩 이동
    
    for (int i = 0; i < name.size(); i++) {
        int next = i + 1;
        
        // 연속 A 건너뛰기 (오른쪽으로)
        while (next < name.size() && name[next] == 'A')
            next++;
        
        // -> 오른쪽 -> 왼쪽
        int move1 = i + i + name.size() - next;
        // -> 왼쪽 -> 오른쪽
        int move2 = (name.size() - next) * 2 + i;
        
        // 오른쪽으로 가는 경우, 왼쪽으로 가는 경우 비교
        minMove = min(minMove, min(move1, move2));
    }
    
    answer += minMove;
    return answer;
}
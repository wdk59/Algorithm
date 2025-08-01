#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 설치 조건 체크 함수
bool canInstall(int x, int y, int a, const set<vector<int>>& s) {
    if (a == 0) { // 기둥
        return y == 0 || 
               s.count({x, y - 1, 0}) || 
               s.count({x - 1, y, 1}) || 
               s.count({x, y, 1});
    } else { // 보
        return s.count({x, y - 1, 0}) || 
               s.count({x + 1, y - 1, 0}) || 
               (s.count({x - 1, y, 1}) && s.count({x + 1, y, 1}));
    }
}

// 전체 구조물이 유효한지 확인 (삭제 시 사용)
bool isValid(const set<vector<int>>& s) {
    for (const auto& el : s) {
        int x = el[0], y = el[1], a = el[2];
        if (!canInstall(x, y, a, s)) return false;
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    set<vector<int>> structure;

    for (const auto& frame : build_frame) {
        int x = frame[0], y = frame[1], a = frame[2], b = frame[3];

        if (b == 1) { // 설치
            structure.insert({x, y, a});
            if (!canInstall(x, y, a, structure))
                structure.erase({x, y, a});
        } else { // 삭제
            structure.erase({x, y, a});
            if (!isValid(structure))
                structure.insert({x, y, a});
        }
    }

    vector<vector<int>> answer(structure.begin(), structure.end());
    sort(answer.begin(), answer.end()); // 정렬 조건: x → y → a
    return answer;
}

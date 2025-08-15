#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    /* 보석 종류 개수 세기 */
    unordered_map<string, int> gemCnt;
    for (string gem: gems)
        gemCnt[gem]++;
    int gemTypes = gemCnt.size();
    if (gemTypes == 1)
        return {1, 1};
    
    /* 보석 고르기 */
    gemCnt.clear();
    int left = 0, right = 0, minLength = gems.size();
    while (right < gems.size()) {
        // 일단 담기
        gemCnt[gems[right]]++;
        // 보석 종류 다 모으면 범위 줄이기
        while (gemTypes == gemCnt.size()) {
            // 지금 찾은 길이가 최소이면 갱신
            if (minLength > right - left) {
                minLength = right - left;
                answer = {left + 1, right + 1};
            }
            // 범위 줄이기: left 이동
            if (--gemCnt[gems[left]] == 0)
                gemCnt.erase(gems[left]);
            left++;
        }
        
        // 모자란 보석 찾기: right 이동
        right++;
    }
    
    return answer;
}
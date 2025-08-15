#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    // 아는 번호 중 당첨 번호에 속하는 번호 개수 세기
    int cnt = 0, zeroCnt = 0;
    for (int num: lottos) {
        if (num == 0)
            zeroCnt++;
        else if (find(win_nums.begin(), win_nums.end(), num) != win_nums.end())
            cnt++;
    }
    
    // 최고 순위: 모르는 번호 다 맞는 경우
    // 최저 순위: 모르는 번호 다 틀린 경우
    int maxCnt = cnt + zeroCnt;
    
    answer.push_back(7 - maxCnt < 6 ? 7 - maxCnt : 6);
    answer.push_back(7 - cnt < 6 ? 7 - cnt : 6);
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while (s != "1") {
        int cnt_one = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                cnt_one++;
            else
                answer[1]++;
        }
        
        // 이진 변환
        s = "";
        while (cnt_one != 0) {
            s += to_string(cnt_one % 2);
            cnt_one /= 2;
        }
        
        answer[0]++;
    }
    
    return answer;
}
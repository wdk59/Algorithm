#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> tan_map;
    for (int i = 0; i < tangerine.size(); i++)
        tan_map[tangerine[i]]++;
    
    vector<int> tan_cnt;
    for (int i = 0; i < tan_map.size(); i++)
        tan_cnt.push_back(tan_map[i]);
    sort(tan_cnt.rbegin(), tan_cnt.rend());
    
    for (answer = 0; answer < tan_cnt.size(); answer++) {
        k -= tan_cnt[answer];
        
        if (k <= 0)
            break;
    }
    
    return answer + 1;  // tan_cnt가 0-based기 때문에 1 더해주기
}
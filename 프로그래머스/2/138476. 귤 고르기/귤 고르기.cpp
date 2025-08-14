#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> tan_cnt;
    for (int i = 0; i < tangerine.size(); i++)
        tan_cnt[tangerine[i]]++;
    
    vector<pair<int, int>> tan_vec(tan_cnt.begin(), tan_cnt.end());
    sort(tan_vec.begin(), tan_vec.end(), compare);
    
    for (answer = 0; answer < tan_vec.size(); answer++) {
        k -= tan_vec[answer].second;
        
        if (k <= 0)
            break;
    }
    
    return answer + 1;
}
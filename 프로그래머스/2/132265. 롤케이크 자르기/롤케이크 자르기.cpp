#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int, int> bro, me;
    // bro한테 다 주고 시작
    for (int t: topping)
        bro[t]++;
    
    // 하나씩 가져오면서 서로 개수 같을 때마다 1++
    int broCnt = bro.size();
    for (int t: topping) {
        bro[t]--;   me[t]++;
        if (bro[t] == 0)
            broCnt--;
        if (broCnt == me.size())
            answer++;
    }

    return answer;
}
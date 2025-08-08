#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    vector<int> dp1(money.size(), 0);
    vector<int> dp2(money.size(), 0);
    
    dp1[0] = dp1[1] = money[0];
    dp2[0] = 0;
    dp2[1] = money[1];
    
    for (int i = 2; i < money.size(); i++) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
    }
    
    return max(dp1[money.size() - 2], dp2[money.size() - 1]);
}

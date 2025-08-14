#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    int i = 0;
    while (budget > 0 && i < d.size()) {
        if (budget >= d[i]) {
            budget -= d[i];
            answer++;
        }
        i++;
    }
    
    return answer;
}
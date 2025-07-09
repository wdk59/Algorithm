#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    int i = 0;
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= citations.size() - i)
            return citations.size() - i;
    }
    
    return 0;
}
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> cloth(n, 1);
    for (int i = 0; i < lost.size(); i++)
        cloth[lost[i] - 1]--;
    for (int i = 0; i < reserve.size(); i++)
        cloth[reserve[i] - 1]++;
    
    for (int i = 0; i < n; i++) {
        if (cloth[i] == 0) {
            if (i > 0 && cloth[i - 1] == 2) {
                cloth[i - 1]--;
                cloth[i]++;
            } else if (i < n - 1 && cloth[i + 1] == 2) {
                cloth[i + 1]--;
                cloth[i]++;
            }
        }
    }
    
    for (int i: cloth)
        if (i > 0)
            answer++;
    
    return answer;
}
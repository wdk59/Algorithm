#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 약수 구하기
    vector<int> divisor;
    for (int i = 1; i <= yellow / 2; i++)
        if (yellow % i == 0)
            divisor.push_back(i);
    divisor.push_back(yellow);
    
    // 경우 따지기
    for (int h: divisor) {
        int w = yellow / h;
        if (brown == (h + w) * 2 + 4) {
            answer.push_back(w + 2);
            answer.push_back(h + 2);
            break;
        }
    }
    
    return answer;
}
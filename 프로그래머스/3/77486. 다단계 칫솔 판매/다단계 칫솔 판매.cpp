#include <vector>
#include <map>

using namespace std;

map<string, string> parent;
map<string, int> totalGain;

// 내가 번 돈 상사한테 10% 뺏기는데, 상사도 본인 상사한테 10% 뺏김
void calGain(string seller, int gain) {
    // 보스까지 가면 끝
    if (seller == "-")
        return;
    
    int commision = gain * 0.1;
    totalGain[seller] += gain - commision;
    
    // 더 이상 수수료가 안 나올 정도로 수입이 적어지면 더 반복할 필요 없음
    if (commision == 0)
        return;
    
    // 상사한테 수수료 전달
    calGain(parent[seller], commision);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for (int i = 0; i < enroll.size(); i++)
        parent[enroll[i]] = referral[i];
    
    // 최초 수입: seller한테서만 발생
    for (int i = 0; i < seller.size(); i++)
        calGain(seller[i], amount[i] * 100);
    
    // 결과 저장
    for (int i = 0; i < enroll.size(); i++)
        answer.push_back(totalGain[enroll[i]]);
    
    return answer;
}
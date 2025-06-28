#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;   // 앞의 일을 우선으로 처리해야 하기 때문에 큐 사용
    for (int i = 0; i < progresses.size(); i++)
        q.push(i);
    
    int cnt = 0;
    while (!q.empty()) {
        cnt = 0;
        for (int i = 0; i < speeds.size(); i++)
            progresses[i] += speeds[i];
            
        while (!q.empty() && progresses[q.front()] >= 100) {
            cnt++;
            q.pop();
        }
        if (cnt > 0)
            answer.push_back(cnt);
    }
    
    return answer;
}
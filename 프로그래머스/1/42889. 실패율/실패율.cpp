#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<int> visited(N + 2, 0);  // 스테이지를 모두 클리어하면 N+1에 위치함
    for (int i = 0; i < stages.size(); i++)
        visited[stages[i]]++;
    
    int visitedNum = stages.size();
    vector<pair<int, double>> failure;
    double tmp = 0;
    for (int i = 1; i <= N; i++) {
        tmp = 0;
        if (visitedNum != 0)
            tmp = static_cast<double>(visited[i]) / visitedNum;
        failure.push_back(make_pair(i, tmp));  // (double)로 형변환하는 건 C스타일로, 오래된 형변환이라고 한다.
        visitedNum -= visited[i];
    }
    
    sort(failure.begin(), failure.end(), compare);
    
    for (int i = 0; i < failure.size(); i++)
        answer.push_back(failure[i].first);
    
    return answer;
}
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if (a[0] == b[0])
        return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), compare);
    
    int lastLoc = -30001;
    for (int i = 0; i < routes.size(); i++) {
        // 현재 차량이 마지막 카메라의 범위 밖이면 현재 차량의 마지막 지점에 카메라 설치
        if (routes[i][0] > lastLoc) {
            answer++;
            lastLoc = routes[i][1];
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool costCompare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int getParent(int idx, vector<int> nodes){
    if(nodes[idx] == idx)
        return idx;
    return nodes[idx] = getParent(nodes[idx], nodes);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> nodes(n,0);
   
    sort(costs.begin(), costs.end(), costCompare);
    for(int i = 0; i < n; i++){
        nodes[i] = i;
    }
    for(int i = 0; i < costs.size(); i++){
        int connect = getParent(costs[i][0], nodes);
        int connected = getParent(costs[i][1], nodes);
        int cost = costs[i][2];
       
        if(connect != connected){
            answer += cost;
            nodes[connected] = connect;
        }
    }
    return answer;
}
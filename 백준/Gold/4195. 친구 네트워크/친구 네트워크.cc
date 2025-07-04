#include <iostream>
#include <unordered_map>
using namespace std;

// < name, ID >
unordered_map<string, int> ID;
int parent[200001], netCnt[200001];

int findRoot(int x) {
    // 본인이 Root이면 바로 반환
    if (parent[x] == x) return x;
    // 부모의 부모 추적해서 Root 찾기
    return parent[x] = findRoot(parent[x]);
}

// 친구 수 반환 (다른 집합에 있으면 합친 후 반환)
int unionNet(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    // 다른 집합이면 집합 합치기 (Root 같으면 같은 집합)
    if (a != b) {
        parent[b] = a;
        netCnt[a] += netCnt[b];
    }
    return netCnt[a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 0, relations = 0, personCnt = 1;
    cin >> t;
    
    string str1 = "", str2 = "";
    while (t--) {
        ID.clear();
        cin >> relations;
        
        // 각 노드의 루트 설정
        for (int i = 1; i <= relations * 2; i++) {
            parent[i] = i;
            netCnt[i] = 1;
        }

        personCnt = 1;
        while (relations--) {
            str1 = "", str2 = "";
            cin >> str1 >> str2;
            // 처음 보는 친구 ID 만들어주기
            if (ID.count(str1) == 0)    ID[str1] = personCnt++;
            if (ID.count(str2) == 0)    ID[str2] = personCnt++;

            // 친구 수 알아내기
            cout << unionNet(ID[str1], ID[str2]) << '\n';
        }
    }

    return 0;
}

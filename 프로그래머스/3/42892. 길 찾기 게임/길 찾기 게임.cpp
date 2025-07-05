#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct NODE {
    int idx;
    int x;
    int y;
    int left = -1, right = -1;
};

bool comp(NODE& a, NODE& b) {
    if (a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}

void insert(vector<NODE>& tree, int parent, int child) {
    // child가 parent의 왼쪽 트리에 속할 때
    if (tree[child].x < tree[parent].x) {
        if (tree[parent].left == -1)
            tree[parent].left = child;
        else
            insert(tree, tree[parent].left, child);
    } else {
        if (tree[parent].right == -1)
            tree[parent].right = child;
        else
            insert(tree, tree[parent].right, child);
    }
}

void preorder(vector<NODE>& tree, int node, vector<int>& answer) {
    // 부모 노드가 말단 노드였으면 순회 중지
    if (node == -1)
        return;
    
    answer.push_back(tree[node].idx);
    preorder(tree, tree[node].left, answer);
    preorder(tree, tree[node].right, answer);
}

void postorder(vector<NODE>& tree, int node, vector<int>& answer) {
    // 부모 노드가 말단 노드였으면 순회 중지
    if (node == -1)
        return;
    
    postorder(tree, tree[node].left, answer);
    postorder(tree, tree[node].right, answer);
    answer.push_back(tree[node].idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2, vector<int>());
    
    vector<NODE> tree;
    for (int i = 0; i < nodeinfo.size(); i++)
        tree.push_back({i + 1, nodeinfo[i][0], nodeinfo[i][1]});
    
    // 레벨이 높은 노드 순으로 정렬 -> 자식 x위치로 자리 결정 가능
    sort(tree.begin(), tree.end(), comp);
    // 이진 트리 형태로 저장
    for (int i = 1; i < nodeinfo.size(); i++)
        insert(tree, 0, i);
    
    // 전위 순회
    preorder(tree, 0, answer[0]);
    // 후위 순회
    postorder(tree, 0, answer[1]);
    
    return answer;
}
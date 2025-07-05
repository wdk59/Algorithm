#include <iostream>
#include <vector>
using namespace std;

vector<int> inorder;
vector<int> postorder;
vector<int> inorderIdx(100000, 0);

void preorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd)
        return;

    // root 찾기: 후위 순회의 마지막
    int rootIdx = inorderIdx[postorder[postEnd]];
    cout << postorder[postEnd] << ' ';

    // 트리 분할: 중위 순회에서 루트 기점 분할
    int leftSize = rootIdx - inStart;

    // 왼쪽 트리 전위순회
    preorder(inStart, rootIdx - 1, postStart, postStart + leftSize - 1);
    // 오른쪽 트리 전위순회
    preorder(rootIdx + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0, tmp = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        inorder.push_back(tmp);
        inorderIdx[tmp] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        postorder.push_back(tmp);
    }

    preorder(0, n - 1, 0, n - 1);

    return 0;
}

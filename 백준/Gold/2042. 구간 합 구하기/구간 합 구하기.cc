#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long init(vector<long long>& segTree, vector<long long>& nums, int node, int left, int right) {
    if (left == right)
        return segTree[node] = nums[left];

    int mid = (left + right) / 2;
    return segTree[node] = init(segTree, nums, 2 * node, left, mid) + init(segTree, nums, 2 * node + 1, mid + 1, right);
}

void update(vector<long long>& segTree, int node, int left, int right, long long idx, long long diff) {
    if (idx < left || idx > right) return;
    segTree[node] += diff;

    if (left != right) {
        int mid = (left + right) / 2;
        update(segTree, node * 2, left, mid, idx, diff);
        update(segTree, node * 2 + 1, mid + 1, right, idx, diff);
    }
}

// 구간 합 구하기 함수
long long sum(const vector<long long>& segTree, int node, int left, int right, long long rangeL, long long rangeR) {
    if (rangeR < left || right < rangeL) return 0;  // 범위 밖
    if (rangeL <= left && right <= rangeR) return segTree[node]; // 범위 안

    int mid = (left + right) / 2;
    return sum(segTree, 2 * node, left, mid, rangeL, rangeR) + sum(segTree, 2 * node + 1, mid + 1, right, rangeL, rangeR);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> nums(N + 1);  // 1-based
    vector<long long> segTree(N * 4);

    for (int i = 1; i <= N; i++)
        cin >> nums[i];

    init(segTree, nums, 1, 1, N);

    long long cmd = 0, b = 0, c = 0;
    for (int i = 0; i < M + K; i++) {
        cin >> cmd;

        if (cmd == 1) {
            cin >> b >> c;
            long long diff = c - nums[b];
            update(segTree, 1, 1, N, b, diff);
            nums[b] = c;
        }
        else if (cmd == 2) {
            cin >> b >> c;
            cout << sum(segTree, 1, 1, N, b, c) << '\n';
        }
    }

    return 0;
}

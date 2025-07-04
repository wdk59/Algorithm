#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& heap, int a_idx, int b_idx) {
    int tmp = 0;
    tmp = heap[a_idx];
    heap[a_idx] = heap[b_idx];
    heap[b_idx] = tmp;
}

void push(vector<int>& heap, int& rear, int item) {
    // heap 맨 뒤에 삽입 원소 넣기
    int idx = ++rear;
    heap[idx] = item;
    
    // 자리 정렬 (idx가 루트이거나 제대로 정렬 됐으면 그만)
    while ((idx != 1) && (heap[idx / 2] > heap[idx])) {
        // 부모가 더 크면 자리 올려주기
        swap(heap, idx / 2, idx);
        idx /= 2;   // 올라간 자리 가리키기
    }
}

int pop(vector<int>& heap, int& rear) {
    int result = heap[1];

    heap[1] = heap[rear--];
    int idx = 1;            // 기준 부모: 루트부터 시작
    int child_idx = idx * 2;    // 자리 바꿀 자식

    // 자리 정렬 (idx의 자식이 없거나 제대로 정렬 됐으면 그만)
    while (child_idx <= rear) {
        if ((child_idx + 1 <= rear) && heap[child_idx] > heap[child_idx + 1])
            child_idx++;
        if (heap[idx] <= heap[child_idx])
            break;
        swap(heap, idx, child_idx);
        idx = child_idx;
        child_idx = idx * 2;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> heap(100001, 0);
    int rear = 0;   // heap의 맨 마지막을 가리킴

    int num = 0, cmd = 0;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> cmd;
        if (cmd == 0)
            if (rear == 0)
                cout << 0 << '\n';
            else
                cout << pop(heap, rear) << '\n';
        else
            push(heap, rear, cmd);
    }

    return 0;
}

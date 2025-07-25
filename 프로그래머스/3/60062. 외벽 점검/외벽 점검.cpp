#include <algorithm>
#include <vector>

using namespace std;

int answer = 9;
vector<int> weak_extended;

void dfs(int start, vector<int>& dist_used, vector<bool>& visited, const vector<int>& dist, int depth, int weak_start, int len) {
    // 이미 구한 최소 인원보다 많아지면 더 볼 필요 없음
    if (depth >= answer)
        return;

    int friend_dist = dist_used[depth];

    int cover_end = weak_extended[start] + friend_dist;

    int idx = start;
    while (idx < weak_extended.size() && weak_extended[idx] <= cover_end)
        idx++;

    // 현재 친구가 모든 약점 커버
    if (idx - weak_start >= len) {
        answer = min(answer, depth + 1);
        return;
    }

    // 다음 친구 투입
    for (int i = 0; i < dist.size(); ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dist_used[depth + 1] = dist[i];
            dfs(idx, dist_used, visited, dist, depth + 1, weak_start, len);
            visited[i] = false;
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int len = weak.size();

    // 선형으로 펼쳐주기
    for (int i = 0; i < len * 2; ++i) {
        weak_extended.push_back(weak[i % len] + (i / len) * n);
    }

    sort(dist.begin(), dist.end(), greater<int>()); // 큰 거리부터 쓰는 게 가지치기에 유리

    for (int i = 0; i < len; ++i) {
        vector<bool> visited(dist.size(), false);
        vector<int> dist_used(dist.size()); // 먼저 투입한 친구 순서로 저장

        for (int j = 0; j < dist.size(); ++j) {
            visited[j] = true;
            dist_used[0] = dist[j];
            dfs(i, dist_used, visited, dist, 0, i, len);
            visited[j] = false;
        }
    }

    return (answer == 9) ? -1 : answer;
}

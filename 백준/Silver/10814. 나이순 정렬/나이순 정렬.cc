#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool order(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0, tmpAge = 0;
    string tmpName = "";
    cin >> N;
    vector<pair<int, string>> members(N);
    for (int i = 0; i < N; i++)
        cin >> members[i].first >> members[i].second;
    
    stable_sort(members.begin(), members.end(), order);
    for (int i = 0; i < members.size(); i++)
        cout << members[i].first << ' ' << members[i].second << '\n';

    return 0;
}

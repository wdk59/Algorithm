#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool order(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0, tmpA = 0, tmpB = 0;
    cin >> N;
    vector<pair<int, int>> num;
    for (int i = 0; i < N; i++) {
        cin >> tmpA >> tmpB;
        num.push_back(make_pair(tmpA, tmpB));
    }
    
    sort(num.begin(), num.end(), order);
    for (int i = 0; i < num.size(); i++)
        cout << num[i].first << ' ' << num[i].second << '\n';

    return 0;
}

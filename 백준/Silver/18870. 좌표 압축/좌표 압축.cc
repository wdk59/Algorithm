#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    cin >> N;
    vector<int> num(N);
    for (int i = 0; i < N; i++)
        cin >> num[i];

    set<int> cmpSet(num.begin(), num.end());
    vector<int> cmpVec(cmpSet.begin(), cmpSet.end());
    
    int idx = 0;
    for (int i = 0; i < N; i++) {
        idx = lower_bound(cmpVec.begin(), cmpVec.end(), num[i]) - cmpVec.begin();
        cout << idx << ' ';
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> num(N);

    for (int i = 0; i < N; ++i)
        cin >> num[i];

    vector<int> result = num;
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    for (int val : num)
        cout << lower_bound(result.begin(), result.end(), val) - result.begin() << ' ';
}
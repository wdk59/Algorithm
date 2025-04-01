#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool order(int a, int b) {
    return a > b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string N = "";
    cin >> N;
    vector<int> num(N.size(), 0);
    for (int i = 0; i < N.size(); i++)
        num[i] = N[i] - '0';

    sort(num.begin(), num.end(), order);

    for (int i = 0; i < num.size(); i++)
        cout << num[i];

    return 0;
}

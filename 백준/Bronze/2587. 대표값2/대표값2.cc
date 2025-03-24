#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> num;
    int tmp = 0, sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> tmp;
        sum += tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());

    cout << sum / 5 << '\n' << num[2];

    return 0;
}
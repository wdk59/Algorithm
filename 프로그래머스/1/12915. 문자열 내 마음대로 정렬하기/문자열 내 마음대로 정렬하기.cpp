#include <algorithm>
#include <vector>

using namespace std;

int N = 0;
bool cmp(string& a, string& b) {
    if (a[N] == b[N])
        return a < b;
    return a[N] < b[N];
}

vector<string> solution(vector<string> strings, int n) {
    N = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}
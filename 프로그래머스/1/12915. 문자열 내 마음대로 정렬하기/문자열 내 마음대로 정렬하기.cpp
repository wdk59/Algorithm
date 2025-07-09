#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [n](string a, string b) {
        return (a[n] == b[n] ? a < b : a[n] < b[n]);
    });
    return strings;
}
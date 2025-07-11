#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    string s = to_string(n);
    sort(s.begin(), s.end(), [](char& a, char& b) {
        return a > b;
    });
    return stoll(s);
}
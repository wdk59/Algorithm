#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int solution(int a, int b, int c) {
    int answer = 0;
    
    set<int> s = {a, b, c};
    
    if (s.size() == 1) {
        answer = (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2)) * (pow(a, 3) + pow(b, 3) + pow(c, 3));
    } else if (s.size() == 2) {
        answer = (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2));
    } else {
        answer = a + b + c;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for (int i = 0; i < number.size(); i++) {
        while (k > 0 && answer != "" && answer[answer.size() - 1] < number[i]) {
            answer.pop_back();
            k--;
        }
        answer += number[i];
    }
    
    return answer.substr(0, answer.size() - k); // 마지막에 들어온 수를 제거해야 할 수도 있음
}
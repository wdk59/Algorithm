#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct NAME {
    string head;
    int number;
    string origin;
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<NAME> divide(files.size(), {"", -1, ""});
    string tmp = "";
    for (int i = 0; i < files.size(); i++) {
        tmp = "";
        divide[i].origin = files[i];
        for (int j = 0; j < files[i].size(); j++) {
            if (isdigit(files[i][j])) {
                // 숫자 나왔을 때 head 없으면 head에 tmp 넣고 number 모으기
                if (divide[i].head == "") {
                    divide[i].head = tmp;
                    tmp = files[i][j];
                } else {
                    tmp += files[i][j];
                }
            }
            else {
                // 숫자가 아닌 문자 나왔을 때 head 없으면 head 모으고, 아니면 number 저장 후 다음 파일명으로 넘어가기
                if (divide[i].head == "") {
                    tmp += tolower(files[i][j]);
                } else {
                    break;
                }
            }
        }
        divide[i].number = stoi(tmp);
    }
    
    stable_sort(divide.begin(), divide.end(), [](const NAME& a, const NAME& b) {
        return a.head == b.head ? a.number < b.number : a.head < b.head;
    });
    
    for (int i = 0; i < divide.size(); i++)
        answer.push_back(divide[i].origin);
    
    return answer;
}
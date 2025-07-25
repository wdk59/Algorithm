#include <string>
#include <vector>

using namespace std;

string vowel = "AEIOU";

void dfs(int& cnt, int& answer, string& target, string word) {
    cnt++;
    
    if (word == target) {
        answer = cnt;
        return;
    }
    
    if (word.length() >= 5)
        return;
    
    for (char v: vowel)
        dfs(cnt, answer, target, word + v);
}

int solution(string word) {
    int answer = 0;
    
    int cnt = -1;
    string target = word;
    
    dfs(cnt, answer, target, "");
    
    return answer;
}
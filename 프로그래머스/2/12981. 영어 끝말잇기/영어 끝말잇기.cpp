#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    
    for (int i = 1; i < words.size(); i++) {
        if (find(words.begin(), words.begin() + i, words[i]) != words.begin() + i || words[i - 1].back() != words[i][0]) {
            answer = {i % n + 1, i / n + 1};
            break;
        }
    }

    return answer;
}
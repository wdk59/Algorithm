#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<vector<int>> students = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    vector<int> scores(3, 0);
    
    for (int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (answers[i] == students[j][i % students[j].size()])
                scores[j]++;
        }
    }
    
    int max = *max_element(scores.begin(), scores.end());
    for (int i = 0; i < 3; i++) {
        if (max == scores[i])
            answer.push_back(i + 1);
    }
    
    return answer;
}
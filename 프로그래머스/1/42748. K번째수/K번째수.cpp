#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> vec: commands){
        vector<int> tmp;
        for(int j = vec[0] - 1; j < vec[1]; j++){
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[vec[2] - 1]);
    }
    return answer;
}
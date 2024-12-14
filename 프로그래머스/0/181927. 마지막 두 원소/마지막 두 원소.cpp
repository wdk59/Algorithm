#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    answer = num_list;
    int a = num_list[num_list.size() - 1] > num_list[num_list.size() - 2] ? num_list[num_list.size() - 1] - num_list[num_list.size() - 2] : num_list[answer.size() - 1] * 2;
    answer.push_back(a);
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    answer = num_list;
    answer.push_back(*(num_list.end() - 1) > *(num_list.end() - 2) ? *(num_list.end() - 1) - *(num_list.end() - 2) : *(num_list.end() - 1) * 2);
    
    return answer;
}
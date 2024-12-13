#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    answer = accumulate(num_list.begin(), num_list.end(), 1, multiplies<int>()) < pow(accumulate(num_list.begin(), num_list.end(), 0), 2) ? 1 : 0;
    
    return answer;
}
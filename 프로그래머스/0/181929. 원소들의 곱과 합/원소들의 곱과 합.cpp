#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int multi = 1;
    
    for (int i = 0 ; i < num_list.size(); i++) {
        multi *= num_list[i];
    }
    
    answer = multi < pow(accumulate(num_list.begin(), num_list.end(), 0), 2) ? 1 : 0;
    
    return answer;
}
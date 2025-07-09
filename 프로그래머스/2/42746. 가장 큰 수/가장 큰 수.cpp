#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> nums;
    for (int i = 0; i < numbers.size(); i++)
        nums.push_back(to_string(numbers[i]));
    sort(nums.begin(), nums.end(), [](string& a, string& b) { return a + b > b + a; });
    
    for (string i: nums)
        answer += i;
    
    return answer[0] == '0' ? "0" : answer;
}
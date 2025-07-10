#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, bool> map;
    for (int i = 0; i < nums.size(); i++)
        map[nums[i]] = true;
    
    return map.size() < nums.size() / 2 ? map.size() : nums.size() / 2;
}
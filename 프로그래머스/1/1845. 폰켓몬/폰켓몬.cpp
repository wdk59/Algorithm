#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> map(nums.begin(), nums.end());
    
    return map.size() < nums.size() / 2 ? map.size() : nums.size() / 2;
}
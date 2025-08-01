#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0, s = 0;
    cin >> n >> s;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
     
    int left = 0, right = 0, sum = nums[0], min = 100001;
    while (right < nums.size()) {
        if (sum < s) {
            if (right == nums.size() - 1)
                break;
            sum += nums[++right];
        }
        else {
            min = (min > (right - left + 1) ? (right - left + 1) : min);
            sum -= nums[left++];
        }
    }
    
    cout << (min == 100001 ? 0 : min);

    return 0;
}

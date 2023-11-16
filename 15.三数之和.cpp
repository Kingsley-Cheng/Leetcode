#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 3)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
                return ans;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int L = i + 1;
            int R = n - 1;
            while (L < R)
            {
                if (nums[i] + nums[L] + nums[R] == 0)
                {
                    ans.push_back(vector<int>{nums[i], nums[L], nums[R]});
                    while (L < R && nums[L] == nums[L + 1])
                        ++L;
                    while (L < R && nums[R] == nums[R - 1])
                        --R;
                    ++L;
                    --R;
                }
                else if (nums[i] + nums[L] + nums[R] > 0)
                    --R;
                else
                    ++L;
            }
        }
        return ans;
    }
};
// @lc code=end

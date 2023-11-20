#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        if (nums.size() < 4)
            return ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if ((long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
                continue;
            for (int j = i + 1; j < n - 2; ++j)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if ((long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                    continue;
                int tmp = target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;
                while (l < r)
                {
                    int tmp2 = nums[l] + nums[r];
                    if (tmp2 > tmp)
                    {
                        --r;
                        while (l < r && nums[r] == nums[r + 1])
                            --r;
                    }
                    else if (tmp2 < tmp)
                    {
                        ++l;
                        while (l < r && nums[l] == nums[l - 1])
                            ++l;
                    }
                    else
                    {
                        ans.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        while (l < r && nums[l] == nums[l - 1])
                            ++l;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int result = INT16_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int tmp = nums[i] + nums[l] + nums[r];
                result = (abs(target - tmp) > abs(target - result)) ? result : (nums[i] + nums[l] + nums[r]);
                if (tmp > target)
                    --r;
                else if (tmp < target)
                    ++l;
                else
                    return target;
            }
        }
        return result;
    }
};
// @lc code=end

// int main()
// {
//     Solution sl;
//     vector<int> nums{-1, 2, 1, -4};
//     cout<<sl.threeSumClosest(nums, 1)<<endl;
// }
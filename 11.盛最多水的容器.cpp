#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = 0;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            int tmp = (j - i) * ((height[i] <= height[j]) ? height[i] : height[j]);
            ans = (tmp > ans) ? tmp : ans;
            if (height[i] >= height[j])
                --j;
            else
                ++i;
        }
        return ans;
    }
};
// @lc code=end

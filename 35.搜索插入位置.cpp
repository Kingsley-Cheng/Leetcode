#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1, ans=nums.size();    
        while (l<=r)
        {
            int mid = l + ((r-l)>>1);
            if(target<=nums[mid]){
                r=mid-1;
                ans=mid;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};
// @lc code=end


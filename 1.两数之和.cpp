// #include<map>
// #include<vector>
// using namespace std;
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> Hashmap;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (Hashmap.find(target - nums[i]) == Hashmap.end())
                Hashmap.insert(pair<int, int>(nums[i], i));
            else
                return vector<int>{Hashmap.find(target - nums[i])->second, i};
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end

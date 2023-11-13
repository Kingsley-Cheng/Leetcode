#include <vector>
#include <string>
using namespace std;

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (!strs.size())
            return "";
        else
            return longestCommonPrefix(strs, 0, strs.size() - 1);
    }

    string longestCommonPrefix(vector<string> &strs, int start, int end)
    {
        if (start == end)
            return strs[start];
        else
        {
            int mid = start + (end - start) / 2;
            string left = longestCommonPrefix(strs, start, mid);
            string right = longestCommonPrefix(strs, mid + 1, end);
            return commonPrefix(left, right);
        }
    }
    string commonPrefix(const string &left, const string &right)
    {
        int minlength = min(left.size(), right.size());
        for (int i = 0; i < minlength; ++i)
            if (left[i] != right[i])
                return left.substr(0, i);
        return left.substr(0, minlength);
    }
};
// @lc code=end

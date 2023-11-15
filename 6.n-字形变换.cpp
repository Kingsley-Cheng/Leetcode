#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.size())
            return s;
        int k = 2 * numRows - 2;
        string ans = "";
        for (int j = 0; j < numRows; ++j)
            for (int i = 0; i + j < s.size(); i += k)
            {
                ans += s[i + j];
                if (j > 0 && j < numRows - 1 && i + k - j < s.size())
                    ans += s[i + k - j];
            }
        return ans;
    }
};
// @lc code=end

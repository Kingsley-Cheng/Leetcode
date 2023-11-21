#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        generateParenthesis(ans, "", n, n);
        return ans;
    }
    void generateParenthesis(vector<string> &ans, string tmp, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            ans.push_back(tmp);
            return;
        };
        if (left == right)
            generateParenthesis(ans, tmp + '(', left - 1, right);
        else
        {
            if (left > 0)
                generateParenthesis(ans, tmp + '(', left - 1, right);
            generateParenthesis(ans, tmp + ')', left, right - 1);
        }
    }
};
// @lc code=end

#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size() - 1;
        while (s[n] == ' ')
            n--;
        int lastLen = 0;
        while (n >= 0 && s[n--] != ' ')
            lastLen++;
        return lastLen;
    }
};
// @lc code=end

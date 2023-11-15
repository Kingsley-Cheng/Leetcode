#include <string>
#include <vector>
// #include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    int ExpandAroundCenter(string s, int l, int r)
    {
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            --l;
            ++r;
        }
        return r - l - 1;
    }
    string longestPalindrome(string s)
    {
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int len1 = ExpandAroundCenter(s, i, i);
            int len2 = ExpandAroundCenter(s, i, i + 1);
            int length = (len1 > len2) ? len1 : len2;
            if (length > maxLen)
            {
                maxLen = length;
                start = i - (maxLen - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};
// @lc code=end

// int main()
// {
//     string s="cbbd";
//     Solution sl;
//     cout<<sl.longestPalindrome(s)<<endl;
// }
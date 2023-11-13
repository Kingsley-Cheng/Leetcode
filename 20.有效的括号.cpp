#include <string>
#include <stack>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 == 1)
            return false;
        unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> tmp;
        for (char ch : s)
        {
            if (pairs[ch])
            {
                if (tmp.empty() || tmp.top() != pairs[ch])
                    return false;
                tmp.pop();
            }
            else
                tmp.push(ch);
        }
        return tmp.empty();
    }
};
// @lc code=end

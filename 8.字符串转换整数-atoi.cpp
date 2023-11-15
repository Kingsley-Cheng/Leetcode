#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Automation
{
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}};

    int get_char(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c)
    {
        state = table[state][get_char(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = (sign == 1) ? min(ans, (long long)INT32_MAX) : min(ans, -(long long)INT32_MIN);
        }
        else if (state == "signed")
            sign = (c == '+') ? 1 : -1;
    }
};

class Solution
{
public:
    int myAtoi(string s)
    {
        Automation automation;
        for (char c : s)
            automation.get(c);
        return automation.sign * automation.ans;
    }
};
// @lc code=end

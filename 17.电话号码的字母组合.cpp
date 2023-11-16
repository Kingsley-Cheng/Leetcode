#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.empty())
            return ans;
        string combination;
        unordered_map<char, string> PhoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        backtrack(ans, PhoneMap, digits, 0, combination);
        return ans;
    }

    void backtrack(vector<string> &ans, const unordered_map<char, string> &PhoneMap, const string &digits, int index, string &combination)
    {
        if (index == digits.size())
            ans.push_back(combination);
        else
        {
            char digit = digits[index];
            const string &letters = PhoneMap.at(digit);
            for (const char &letter : letters)
            {
                combination.push_back(letter);
                backtrack(ans, PhoneMap, digits, index+1, combination);
                combination.pop_back();
            }
        }
    }
};
// @lc code=end

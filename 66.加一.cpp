#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        int tens = (digits[n]+1)/10;
        digits[n] = (digits[n]+1)%10;
        while(tens>0&&n>0){
            n--;
            int val = digits[n];
            digits[n] = (digits[n]+tens)%10;
            tens = (val+tens)/10;
        }
        if(tens>0)
            digits.insert(digits.begin(),tens);
        return digits;
    }
};
// @lc code=end


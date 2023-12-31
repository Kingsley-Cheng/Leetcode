#include<string>
using namespace std;

/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        vector<string> thousands{"","M","MM","MMM"};
        vector<string> hundreds{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> tens{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> ones{"","I","II","III","IV","V","VI","VII","VIII","IX"};
        return thousands[num/1000]+hundreds[num%1000/100]+tens[num%100/10]+ones[num%10];
    }
};
// @lc code=end


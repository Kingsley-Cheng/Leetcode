#include<string>
#include<unordered_map>
using  namespace std;
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hashmap;
        int ans =0;
        for(int i=0, j=0; i<s.size(); ++i){
            if(hashmap.find(s[i]) == hashmap.end()){
                j = max(0,j);
            }
            else{
                j = max(hashmap.find(s[i])->second,j);
            }
            hashmap[s[i]] = i+1;
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
// @lc code=end


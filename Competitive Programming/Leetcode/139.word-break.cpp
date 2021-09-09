/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector< bool > dp(s.size(), false);
        int n = s.size();
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = 0 ; j < wordDict.size() ; j++){
                if(wordDict[j].size() <= n - i and 
                    check(i, s, wordDict[j])){
                    if(i + wordDict[j].size() == n)
                        dp[i] = true;
                    else if(i + wordDict[j].size() < n and dp[i + wordDict[j].size()])
                        dp[i] = true;
                    else
                        continue;
                    break;
                }
            }
        }
       return dp[0]; 
    }
    bool check(int index, string &s, string &word){
        for(int i = 0 ; i < word.size() ; i++)
            if(s[i+index] != word[i])
                return false;
        return true;
    }
};
// @lc code=end


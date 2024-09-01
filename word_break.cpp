// https://leetcode.cn/problems/word-break/description/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // first create a unique set that do not contain the repeated elements;
        // complete bag problem
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        // only return true, false;
        vector<bool> dp(301,false);
        dp[0]=true;
        // dp[i] means that string s' (length is i) is true or false;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                // find substring that the initial position is j and length is i-j;
                string sub=s.substr(j,i-j);
                if(word_set.find(sub)!=word_set.end()&&dp[j])
                {
                    dp[i]=true;
                }
            }
        }
        return dp[s.size()];
    }
};
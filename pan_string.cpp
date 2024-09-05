class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size(),0));
        for(int i=0;i<s.size();i++) dp[i][i]=1;
        int maxval=0;
        int left1,right1=0;
        for(int k=0;k<s.size();k++)
        {
            int left, right;
            if(s[k]==s[k+1]){
                left=k-1;
                right=k+2;
                dp[k][k+1]=dp[k][k]+1;
                while(s[left]==s[right]&&left>=0&&right<s.size()){
                    dp[left][right]=dp[left+1][right-1]+2;
                    left--;
                    right++;
                }
                
            }
            if(k>0&&s[k-1]==s[k+1]){
                left=k-1;
                right=k+1;
                while(s[left]==s[right]&&left>=0&&right<s.size()){
                    dp[left][right]=dp[left+1][right-1]+2;
                    left--;
                    right++;
                }
            }
            if(dp[left+1][right-1]>maxval){
                    maxval=dp[left+1][right-1];
                    left1=left+1;
                    right1=right-1;
                }
        }
        string output;
        for(int i=left1;i<=right1;i++)
        {
            output.push_back(s[i]);
        }
        return output;
    }
};
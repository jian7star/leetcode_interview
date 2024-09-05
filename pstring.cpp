#include<string>
#include<iostream>
#include<vector>
using namespace std;
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         vector<vector<int>> dp(s.size(), vector<int> (s.size(),0));

//         for(int i=0;i<s.size();i++) dp[i][i]=1;
//         int val=1;
//         int left1=0,right1=0;
//         for(int k=0;k<s.size();k++)
//         {
//             int left=0, right=0;
//             if(s[k]==s[k+1]){
//                 left=k;
//                 right=k+1;
//                 dp[left][right]=dp[left][right-1]+1;
//                 max_val(left1,right1,val,dp[left][right],left,right);

//                 while(s[left]==s[right]&&left>=0&&right<s.size()){
//                     dp[left][right]=dp[left+1][right-1]+2;
//                     max_val(left1,right1,val,dp[left][right],left,right);
//                     left--;
//                     right++;
//                 }
//             }
//             if(k>0&&s[k-1]==s[k+1]){
//                 left=k-1;
//                 right=k+1;
//                 while(s[left]==s[right]&&left>=0&&right<s.size()){
//                     dp[left][right]=dp[left+1][right-1]+2;
//                     max_val(left1,right1,val,dp[left][right],left,right);
//                     left--;
//                     right++;
//                 }
//             }
            
//         }
//         string output;
//         for(int i=left1;i<=right1;i++)
//         {
//             output.push_back(s[i]);
//         }
//         return output;
//     }
//     void max_val(int& left, int &right, int& val, int val1, int left1, int right1)
//     {
//         if(val1>val){
//             val=val1;
//             left=left1;
//             right=right1;
//         }
//     }
// };
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len<2) return s;
        int maxLen=1;
        int begin=0;
        vector<vector<bool>> dp(len, vector<bool>(len,0));
        for(int i=0;i<len;i++) dp[i][i]=true;
        for(int i=2;i<=len;i++){
            for(int j=0;j<len;j++){
                int right=j+i-1;
                if(right>=len) break;
                if(s[j]==s[right]){
                   if(right-j<3) dp[j][right]=true;
                   else dp[j][right]=dp[j+1][right-1];
                }
                if(len>maxLen&&dp[j][right]){
                        maxLen=i;
                        begin=j;
                }
            }
        }
        cout<<begin<<maxLen;
        return s.substr(begin, maxLen);
    }
};
int main()
{
    Solution s;
    string s1="ac";
    cout<<s.longestPalindrome(s1);

}
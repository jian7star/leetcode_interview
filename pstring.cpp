#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        int n=s.size();
        int max = 0;
        int max_l=0,max_r=0;
        for(int i=0;i<s.size();i++)
        {
            int left=i;
            int right=i;
            while(left>=0&&right<n)
            {
                if(s[left]==s[right]){
                    if(max<right-left+1){
                        max=right-left+1;
                        max_l=left;
                        max_r=right;
                    }
                    left--;
                    right++;
                }else break;}
            left=i;
            right=i;
            while(left>=0&&right<n){

                if(right<n-1&&s[left]==s[right+1]){
                    right++;
                    if(max<right-left+1){
                        max=right-left+1;
                        max_l=left;
                        max_r=right;
                    }
                }else break;
            }    
        }
        string s1;
        for(int i=max_l;i<=max_r;i++)
            s1.push_back(s[i]);
        return s1;
    }   
};
int main()
{
    Solution s;
    string s1="cbbd";
    cout<<    s.longestPalindrome(s1);

}
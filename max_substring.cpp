/*
    Problem: Given a string s, find the length of the longest substring without repeating characters.
    Usually use i,j pointer to refer the start position and last position of the substring.
    1. brute force solution
    2. slide window, use map operation to refer to the substring.
*/
#include "head_file/header.h"

class Solution
{
private:
    unordered_map<char, int> map;
    int start, maxLength;

public:
    Solution(): start(0), maxLength(0){};

    int maxLengthSubstring(const string& s)
    {
        for(int i = 0; i<s.length(); i++)
        {
            if(map.find(s[i])!=map.end() && map[s[i]]>=start)
            {
                start = map[s[i]]+1;
            }
            map[s[i]] = i;
            maxLength = max(maxLength, i-start+1);
        }
        return maxLength;
    }
};

int main()
{
    Solution solution;
    string s;
    cin>>s;
    cout<<solution.maxLengthSubstring(s)<<endl;
}




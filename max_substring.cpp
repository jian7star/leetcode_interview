/*
    Problem: Given a string s, find the length of the longest substring without repeating characters.
    Usually use i,j pointer to refer the start position and last position of the substring.
    1. brute force solution
    2. slide window, use map operation to refer to the substring. Once times happen, we need use hash table unordered_map.
        map implent as a balanced binary search tree and a binary tree. 

*/
#include "head_file/header.h"

class Solution
{    

public:
    int maxLengthSubstring(const string& s)
    {
        unordered_map<char, int> map;
        int start, maxLength;
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




#include<vector>
// Sorting the array helps in skipping duplicates easily and also allows the two-pointer technique to work efficiently.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> triple;
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(n<3||(i+2<n&&(nums[i]+nums[i+1]+nums[i+2]>0))) break;
            if(nums[i]+nums[n-1]+nums[n-2]<0) continue;
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0) {
                    triple.push_back({nums[i],nums[left], nums[right]});
                    while(left<right&&nums[left]==nums[left+1]) left++;
                    while(left<right&&nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }else if(sum<0){ left++;}
                else if(sum>0){right--;}      
                          
            }
        }
        return triple;
    }
};
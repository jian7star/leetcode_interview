#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    vector<int> tmp;
    void sorted(vector<int> &nums)
    {
        int len=nums.size();
        tmp.resize(len,0);
        mergedSort(nums,0,len-1);
    }
    void mergedSort(vector<int>& nums, int l, int r)
    {
        if(l>=r) return;
        int mid=(l+r)>>1;
        mergedSort(nums, l, mid);
        mergedSort(nums, mid+1,r);
        int i=l, j=mid+1;
        int cnt=0;
        while(i<=mid&&j<=r)
        {
            if(nums[i]<nums[j])
            {
                tmp[cnt++]=nums[i++];
            }else{
                tmp[cnt++]=nums[j++];
            }
        }
        while(i<=mid){
            tmp[cnt++]=nums[i];
        }
        while(j<=r)
        {
            tmp[cnt++]=nums[j];
        }
        for(int i=0;i<cnt;i++)
        {
            cout<<tmp[i];
        }
        cout<<endl;
        for(int i=0;i<=r-l+1;i++)
        {
            nums[i+l]=tmp[i];
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums(100,0);
    for(int i=0;i<10;i++)
    {
        int val;
        cin>>val;
        nums.push_back(val);
    }
    s.sorted(nums);
}
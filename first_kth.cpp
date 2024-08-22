#include<queue>
#include "head_file/header.h"

class Solution {
public:
    unordered_map<int, int> map;
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for(int num:nums)
        {
            minHeap.push(num);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
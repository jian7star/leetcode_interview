#include<iostream>
#include<vector>
struct ListNode
{
    /* data */
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* reverse=head;
        ListNode* curr = head;
        while(reverse->next!=nullptr)
        {
            int cnt=0;
            while(cnt<k&&reverse!=nullptr){cnt++; reverse=reverse->next;}
            if(cnt<k&&reverse==nullptr) break;
            while(cnt--)
            {
                ListNode* temp= curr->next;
                curr->next=reverse;
                reverse=curr;
                curr=temp;
            }
            reverse=curr;
        }

        return reverse;
    }
};
int main()
{
    Solution s;
    ListNode node;
    vector<int> a={1,2,3,4,5};
    
}
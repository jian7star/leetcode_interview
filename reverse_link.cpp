/*
brute-force: class Solution {
            public:
                ListNode* reverseList(ListNode* head) {
                    ListNode* reverse = head;
                    ListNode* q = head;
                    int a[5001], count = 0;
                    while(reverse!=nullptr)
                    {
                        a[count] = reverse->val;
                        reverse = reverse-> next;
                        count = count +1;
                    }
                    count = count-1;
                    while(count>=0)
                    {
                        q->val = a[count];
                        q = q->next;
                        count--;
                    }
                    return head;
                }
            };
    2. pointer reverses.
    class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* reverse = nullptr;
            ListNode* curr = head;
            while(curr!=nullptr)
            {
                ListNode* temp = curr->next;
                curr->next = reverse;
                reverse = curr;
                curr = temp;
            }
            return reverse;
        }
};
*/
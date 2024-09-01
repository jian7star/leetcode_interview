# leetcode_interview

# 动态规划

    1. 二叉树，树状结构，推导关系
    2. data，整数分解，推导关系
    3. 0-1 背包问题， dp[i][j]
    4. ~~~problem: https://programmercarl.com/0337.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8DIII.html#%E6%80%9D%E8%B7%AF
    5. 买卖股票的最佳时机III
    6. 买卖股票的最佳时机III
    7. 最佳买卖股票时机含冷冻期
    8. 不相交的线
    9. 动态规划->48


# Link List:
    1. set a virtual node: 
   
   ```
        class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
   ```
1. 经典：https://leetcode.cn/problems/design-linked-list/submissions/559313806/ 
   
   参考：
        https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html#%E6%80%9D%E8%B7%AF

   
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast =head;
        // 判断是否有环
        do{
            if( !fast || !fast->next ) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        }while(fast != slow);
        // 找到环路的起始节点
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* right = head;
        ListNode* left = head;
        for(int i = 0; i <= n; i++){
            if(right == NULL) return head->next;
            right = right->next;
        }
        while(right){
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;
        return head;
    }
};
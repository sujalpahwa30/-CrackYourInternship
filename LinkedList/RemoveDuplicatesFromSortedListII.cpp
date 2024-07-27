class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *temp = dummy;
        while(head != NULL){
            if(head->next and head->val == head->next->val){
                while(head->next and head->val == head->next->val){
                    head = head->next;
                }
                temp->next = head->next;
            }
            else temp = temp->next;
            head = head->next;
        }
        return dummy->next;
    }
};
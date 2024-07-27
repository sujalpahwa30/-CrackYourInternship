class Solution {
public:
int length(ListNode* head){
    int m = 0;
    while(head){
        head = head->next;
        m++;
    }
    return m;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        if(len < k || !head)  return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = dummy;
        ListNode* Next = dummy;
        while(len >= k){
            curr = prev->next;
            Next = curr->next;
            for(int i = 1; i < k; i++){
                curr->next = Next->next;
                Next->next = prev->next;
                prev->next = Next;
                Next = curr->next;
            }
            prev = curr;
            len -= k;
        }
        return dummy->next;
    }
};
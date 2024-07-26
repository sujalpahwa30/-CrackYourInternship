class Solution {
public:
    Node *compute(Node *head) {
        Node *cur = head;
        Node *prev = NULL;
        Node *next;
        while(cur!=NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        Node *current = head;
        Node *maxNode = head;
        Node *temp;
        while (current != NULL && current->next != NULL) {
            if(current->next->data < maxNode->data){
                temp = current->next;
                current->next = temp->next;
                free(temp);
            }
            else {
                current = current->next;
                maxNode= current;
            }
        }
        cur = head;
        prev = NULL;
        next;
        while(cur!=NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        return head;
    }
};

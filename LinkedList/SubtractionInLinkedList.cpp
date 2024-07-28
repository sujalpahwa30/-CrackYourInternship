class Solution {
public:
    void printList(Node* n) {
        while (n) {
            cout << n->data;
            n = n->next;
        }
        cout << endl;
    }
    int length(Node* n) {
        int ret = 0;
        while (n) {
            ret++;
            n = n->next;
        }
        return ret;
    }
    Node* reverse(Node* head) {
        Node* prev =  NULL;
        Node* current = head;
        Node* next =  NULL;

        while (current !=  NULL) {
            next = current->next;
            current->next = prev; 
            prev = current; 
            current = next; 
        }
        return prev;
    }
    Node* subLinkedList(Node* l1, Node* l2) {
        while (l1 !=  NULL && l1->data == 0) {
            l1 = l1->next;
        }
        while (l2 !=  NULL && l2->data == 0) {
            l2 = l2->next;
        }
        int n1 = length(l1);
        int n2 = length(l2);
        if (n1 == 0 && n2 == 0) {
            return new Node(0);
        }
        if (n2 > n1) {
            std::swap(l1, l2);
        }
        if (n1 == n2) {
            Node* t1 = l1;
            Node* t2 = l2;
            while (t1->data == t2->data) {
                t1 = t1->next;
                t2 = t2->next;
                if (t1 ==  NULL) {
                    return new Node(0);
                }
            }
            if (t2->data > t1->data) {
                std::swap(l1, l2);
            }
        }
        l1 = reverse(l1);
        l2 = reverse(l2);
        Node* res =  NULL;
        Node* t1 = l1;
        Node* t2 = l2;
        while (t1 !=  NULL) {
            int small = 0;
            if (t2 !=  NULL) {
                small = t2->data;
            }
            if (t1->data < small) {
                t1->next->data -= 1;
                t1->data += 10;
            }
            Node* n = new Node(t1->data - small);
            n->next = res;
            res = n;
            t1 = t1->next;
            if (t2 !=  NULL) {
                t2 = t2->next;
            }
        }
        while (res->next !=  NULL && res->data == 0) {
            res = res->next;
        }
        return res;
    }
};

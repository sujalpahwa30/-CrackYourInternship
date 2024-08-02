class LRUCache {
public:
class Node {
    public: 
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
    }
};
Node* head = new Node(-1, -1);
Node* tail = new Node(-1, -1);
int cap;
unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;        
    }

    void addNode(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        if (m.find(key_) != m.end()) {
            Node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deleteNode(resnode);
            addNode(resnode);
            m[key_] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {
            Node* existingnode = m[key_];
            m.erase(key_);
            deleteNode(existingnode);
        }
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key_, value));
        m[key_] = head->next;
    }
};

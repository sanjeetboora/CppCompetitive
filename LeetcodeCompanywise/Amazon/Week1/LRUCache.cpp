class Node {
public :
    int keyData;
    int valData;
    Node* prev;
    Node* next;
};
class LRUCache {
public:
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int llSize;
    int maxSize;
    LRUCache(int capacity) {
        llSize = 0;
        maxSize = capacity;
        head = new Node();
        tail = new Node();

        head -> next = tail;
        head -> prev = NULL;
        tail -> prev = head;
        tail -> next = NULL;
    }

    void removeNode(int k) {
        Node* n = mp[k];
        n->next -> prev = n->prev;
        n->prev->next = n->next;
        mp[k] = NULL;
        delete n;
    }

    void removeEnd() {
        Node* n = tail->prev;

        n->next->prev = n->prev;
        n->prev->next = n->next;

        mp[n->keyData] = NULL;
        delete n;
    }

    void addFront(int k, int val) {
        Node* n = new Node();
        n -> keyData = k;
        n -> valData = val;
        n->next = head->next;
        n->prev = head;
        head -> next -> prev = n;
        head -> next = n;

        mp[k] = n;
    }


    int get(int key) {
        if (mp.count(key) and mp[key] != NULL) {
            int val = mp[key]->valData;
            removeNode(key);
            addFront(key, val);
            return mp[key] -> valData;
        }

        return -1;
    }

    void put(int key, int value) {
        if (mp.count(key) and mp[key] != NULL) {
            removeNode(key);
            addFront(key, value);
        }
        else {
            if (llSize >= maxSize) {
                removeEnd();
                addFront(key, value);
            }

            else {
                addFront(key, value);
                llSize++;
            }

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
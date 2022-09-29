class node {
    public:
        int val;
        int key;
        node*prev, *next;
        node (int v, int k): val(v), key(k){};  
};

class LRUCache {
public:
    
    unordered_map<int, node*>num;//key, index
    int size = 0, limit;
    node* head, *tail;
    void popTail() {
        node* tmp = tail->next->next;
        tmp->prev = tail;
        tail->next = tmp;
    }
    void remove(node* n) {
        node* f = n->next;
        node* b = n->prev;
        f->prev = b;
        b->next = f;
    }
    void add(node* n) {
        node* p = head->prev;
        p->next = n;
        head->prev = n;
        n->next = head;
        n->prev = p;
    }
    void move2Head (node* n) {
        remove(n);
        add(n);
    }
    LRUCache(int capacity) {
        limit = capacity;
        head = new node(-1, -1);
        tail = new node(-2, -1);
        head->next = nullptr;
        head->prev = tail;
        tail->next = head;
        tail->prev = nullptr;
    }
    
    int get(int key) {
        if (num.count(key)) {
            node* n = num[key];
            move2Head(n);
            return n->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (num.count(key)) {
            num[key]->val = value;
            move2Head(num[key]);
        } else {
            if (size < limit) {
                size++;
                node* n = new node(value, key);
                num[key] = n;
                add(n);
                return;
            } 
            

            int temp = tail->next->key;
            popTail();
            node* n = new node(value, key);
            num.erase(temp);
            num[key] = n;
            add(n);

        }
        return;
    }
};

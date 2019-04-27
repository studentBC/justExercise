auto speedup =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class MyHashMap 
{    
    static constexpr int BUCKET_COUNT = 101;        
    
    class node_t 
    {
        // disable copy because of the next pointer
        node_t(const node_t&) = delete;
        node_t& operator=(const node_t&) = delete;
        
    public:
        const int   key;
        int         value;
        node_t*     next;        
        
        // default ctor so we can use vector<node_t>
        node_t() : key(-1), value(-1), next(nullptr) {}
        
        // ctor for inserting keys
        node_t(int key, int value, node_t* next) : key(key), value(value), next(next) {}        
        
        ~node_t() { delete next; }
    };
    
    vector<node_t*> _bucket;
    
    static inline int bidx(int key)
    {
        hash<int> h;
        return h(key) % BUCKET_COUNT;
    }
    
public:
    MyHashMap() : _bucket(BUCKET_COUNT, nullptr) {}    
    ~MyHashMap() {}
    
    void put(int key, int value) 
    {   
        const int idx = bidx(key);
        node_t *cur = _bucket[idx];
        while (cur && cur->key != key) 
            cur = cur->next;
        if (cur) 
            cur->value = value;
        else
            _bucket[idx] = new node_t(key, value, _bucket[idx]);
    }
    
    int get(int key)
    {
        node_t* cur = _bucket[bidx(key)];
        while (cur && cur->key != key)
            cur = cur->next;
        return cur ? cur->value : -1;
    }
    
    void remove(int key) 
    {
        const int idx = bidx(key);
        node_t* cur = _bucket[idx];
        node_t* prev = nullptr;
        while (cur && cur->key != key) {
            prev = cur;
            cur = cur->next;
        }
        if (cur) {
            (prev ? prev->next : _bucket[idx]) = cur->next;
            cur->next = nullptr;
            delete cur;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

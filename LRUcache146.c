typedef struct {
    int agebit;
    int key;
    int value;
    bool dirtybit;
    int capacity;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
  LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache)*capacity);
  for (int i = 0; i < capacity; i++) {
      cache[i].agebit = 0;
      cache[i].dirtybit = false;
      cache[i].key = -1;
      cache[i].capacity = capacity;
  }
  return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    int max = -1, getbit = -1;
    for (int i = 0; i < obj[0].capacity; i++) {
        if (max < obj[i].value) max = obj[i].value;
        if (key == obj[i].key) {
            getbit = i;
        }
    }
    if ( getbit > -1) {
        obj[getbit].agebit = max+1;
		printf("get at %d , agebit: %d \n",getbit, obj[i].agebit);
        return obj[getbit].value;
    }
    return -1;
} 

void lRUCachePut(LRUCache* obj, int key, int value) {
    int max = -1, min = INT_MAX , youngest = 0, oldest = 0, getbit = -1;
    for (int i = 0; i < obj[0].capacity; i++) {
        if (!obj[i].dirtybit && getbit > -1) {
            obj[i].key = key;
            obj[i].value = value;
            obj[i].agebit = obj[youngest].agebit+1;
            obj[i].dirtybit = true;
            printf("key: %d , value: %d , agebit: %d\n",obj[i].key , obj[i].value , obj[i].agebit);
            return;
        }
        if (obj[i].key == key ) {
            getbit = i;
        }
        if (obj[i].agebit > max) {
            youngest = i;
            max = obj[i].agebit;
        }
        if (obj[i].agebit < min) {
            oldest = i;
            min = obj[i].agebit;
        }
    }
    if ( getbit > -1 ) {
    printf("getbit : %d , key: %d , value : %d \n", getbit, obj[getbit].key , obj[getbit].value);
        obj[getbit].agebit = max +1;
        obj[getbit].value = value;
        return;
    }
    printf("replace : %d , key: %d , value : %d \n", oldest, obj[oldest].key , obj[oldest].value);
    obj[oldest].key = key;
    obj[oldest].value = value;
    obj[oldest].agebit = max+1;
    obj[oldest].dirtybit = true;
}

void lRUCacheFree(LRUCache* obj) {
    free(obj);
    return;
}



/**
 * Your LRUCache struct will be instantiated and called as such:
 * struct LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */
//fatest method
struct list_node {
        struct list_node *prev;
        struct list_node *next;
};

/* keep list_node at the top to avoid container_of */
struct list_head {
        struct list_node n;
};

struct entry {
        struct list_node node;
        int key;
        int val;
        UT_hash_handle hh;
};

struct LRUCache {
        struct list_head active_list;
        struct list_head inactive_list;
        struct entry *hash;
        struct entry *entries;
};

typedef struct LRUCache LRUCache;

static void list_init(struct list_head *head)
{
        head->n.prev = &head->n;
        head->n.next = &head->n;
}

static void list_add_tail(struct list_head *head, struct list_node *node)
{
        node->next = &head->n;
        node->prev = head->n.prev;
        
        head->n.prev->next = node;
        head->n.prev = node;
}

static void list_del(struct list_node *node)
{
        node->prev->next = node->next;
        node->next->prev = node->prev;
}

static bool list_empty(struct list_head *head)
{
        return head->n.next == &head->n;
}

static struct list_node *list_pop(struct list_head *head)
{
        struct list_node *ret = head->n.next;

        head->n.next->next->prev = &head->n;
        head->n.next = head->n.next->next;
        return ret;
}

LRUCache* lRUCacheCreate(int capacity)
{
        int i;
        LRUCache *cache;
        
        assert(capacity);
        
        cache = calloc(1, sizeof(*cache));
        assert(cache);
        
        list_init(&cache->active_list);
        list_init(&cache->inactive_list);
        
        cache->entries = calloc(capacity, sizeof(*cache->entries));
        assert(cache->entries);
        
        for (i = 0; i < capacity; i++) {
                struct entry *entry = &cache->entries[i];
                
                list_add_tail(&cache->inactive_list, &entry->node);
        }
        return cache;
}

int lRUCacheGet(LRUCache* obj, int key)
{
        struct entry *entry;
        
        HASH_FIND_INT(obj->hash, &key, entry);
        if (entry == NULL) {
                return -1;
        }
        list_del(&entry->node);
        list_add_tail(&obj->active_list, &entry->node);
        return entry->val;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
        struct entry *entry;
        
        HASH_FIND_INT(obj->hash, &key, entry);
        if (entry) {
                list_del(&entry->node);
                list_add_tail(&obj->active_list, &entry->node);
                entry->val = value;
                return;
        }
        if (!list_empty(&obj->inactive_list)) {
                entry = (struct entry *)list_pop(&obj->inactive_list);
        } else {
                assert(!list_empty(&obj->active_list));
                entry = (struct entry *)list_pop(&obj->active_list);
                HASH_DEL(obj->hash, entry);
        }
                
        entry->key = key;
        entry->val = value;
        list_add_tail(&obj->active_list, &entry->node);
        HASH_ADD_INT(obj->hash, key, entry);
}

void lRUCacheFree(LRUCache* obj)
{
        free(obj->entries);
        free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * struct LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */

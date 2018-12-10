int subarraySum(int* nums, int numsSize, int k) {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < numsSize; i++) {
		sum = 0;
		for (int j = i; j < numsSize; j++) {
			sum+=nums[j];
			if (sum == k) {
				count++;
			}
		}
	}
	return count;
}
//fatest method
struct hash_entry {
    uint32_t val;
    struct hash_entry *next;
    int count;
};

uint32_t calc_hash(uint32_t v)
{
    return ((v * UINT32_C(2654435761)) >> 22);
}

static void
hash_add(uint32_t val, struct hash_entry **hash_table)
{
    struct hash_entry *bucket, *entry;
    
    bucket = hash_table[calc_hash(val)];
    entry = calloc(1, sizeof(struct hash_entry));
    entry->val = val;
    entry->count = 1;
    entry->next = bucket;
    hash_table[calc_hash(val)] = entry;
}

static struct hash_entry *
hash_get(uint32_t val, struct hash_entry **hash_table)
{
    struct hash_entry *bucket;
    
    bucket = hash_table[calc_hash(val)];
    while (bucket != NULL) {
        if (bucket->val == val)
            break;
        bucket = bucket->next;
    }
    
    return bucket;
}

static void
hash_destroy(struct hash_entry **hash_table)
{
    int i;
    for (i = 0; i < 1025; i++) {
        struct hash_entry *temp, *cur;
        cur = hash_table[i];
        while (cur != NULL) {
            temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
}    

int
subarraySum(int* nums, int numsSize, int k) {
    struct hash_entry **hash_table = NULL, *entry;
    int i, cur_sum = 0, total_count = 0;
    
    if (nums == NULL || numsSize == 0)
        goto out;

    hash_table = calloc(1025, sizeof(struct hash_entry *));
    hash_add(0, hash_table);
    for (i = 0; i < numsSize; i++) {
        cur_sum += nums[i];
        entry = hash_get(cur_sum - k, hash_table);
        if (entry != NULL)
            total_count += entry->count;
        entry = hash_get(cur_sum, hash_table);
        if (entry != NULL)
            entry->count++;
        else
            hash_add(cur_sum, hash_table);
    }


    hash_destroy(hash_table);
out:
    free(hash_table);
    return total_count;
}

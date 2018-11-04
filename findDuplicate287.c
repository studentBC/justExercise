int push (int* draft, int num, int* count) {
    for (int i = 0; i < *count; i++) {
        if (num == draft[i]) {
            return draft[i];
        }
    }
    draft[*count] = num;
    *count = *count +1;
    return INT_MAX;
}

int findDuplicate(int* nums, int numsSize) {
    int found ,* count = malloc(sizeof(int)) , * draft = malloc(sizeof(int)*numsSize);
    *count = 0;
    for (int i = 0; i < numsSize; i++) {
        found = push(draft,nums[i],count);
        if (found != INT_MAX) {
            return found;
        }
    }   
    return 0;
}

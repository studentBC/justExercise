typedef struct {
    int val;
    struct MinStack * next;
    bool used;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    //printf(" the max size is %d \n",maxSize);
    MinStack * head = (MinStack *)malloc(sizeof(MinStack));
    head->next = NULL;
    head->used = false;
    return head;
    /*
    if (maxSize < 1){
        return NULL;
    }
    MinStack * head = (MinStack *)malloc(sizeof(MinStack));
    head->next = NULL;
    head->used = false;
    MinStack * loc = head;
    int needNew = maxSize -1;
    for(int i = 0; i < needNew; i++) {
        loc->next = (MinStack *)malloc(sizeof(MinStack));
        loc = loc->next;
        loc->used = false;
    }
    loc -> next = NULL;
    return head;
    */
}

void minStackPush(MinStack* obj, int x) {
    MinStack * loc = obj;
    if (obj == NULL) {
        //printf("fucking null \n");
        obj = (MinStack *)malloc(sizeof(MinStack));
        obj ->next = NULL;
        obj ->val = x;
        obj ->used = true;
        return;
    } else{
        if (obj->used == false) {
            obj->val = x;
            obj->used = true;
            return ;
        } 
            while(loc->next) {
                loc = loc ->next;
                if (loc->used == false) {
                    loc->val = x;
                    loc->used = true;
                    return;
                }
            }
            //there is no extra link for our stack so we need to grow it up 
            loc->next = (MinStack *)malloc(sizeof(MinStack));
            loc = loc->next;
            loc -> val = x;
            loc->used = true;
            loc ->next = NULL;
            return;
        
    }
}

void minStackPop(MinStack* obj) {
    MinStack * loc = obj , * prev;
    //printf(" min pop \n");
    while(loc->next) {
            //printf("%d ,", loc->val);
            prev = loc;
            loc = loc ->next;
        }
    //printf("\n pop the last one is %d \n",loc->val);
    free(loc);
    prev->next = NULL;
    return;
}

int minStackTop(MinStack* obj) {
    MinStack * loc = obj;
    //printf(" min stack \n");
    while(loc->next) {
        //printf("%d ,", loc->val);
        loc = loc ->next;
    }
    return loc->val;
}

int minStackGetMin(MinStack* obj) {
    if (obj) {
        MinStack * loc = obj;
        int min = loc->val;
        //printf("%d ," , min);
        while(loc->next) {
                loc = loc ->next;
            //printf("%d ," ,loc->val);
                if (loc->val < min ) {
                    min = loc->val;
                }
            }
        return min;
    }
    return;
}

void minStackFree(MinStack* obj) {
    free(obj);
    return;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */

typedef struct {
    int val;
    struct MinStack * next;
    bool used;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
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
    MinStack * loc = obj;
    while(loc->next) {
            loc = loc ->next;
        }
    free(loc);
    loc = NULL;
    return;
}

int minStackTop(MinStack* obj) {
    MinStack * loc = obj;
    while(loc->next) {
        loc = loc ->next;
    }
    return loc->val;
}

int minStackGetMin(MinStack* obj) {
    if (obj) {
        MinStack * loc = obj;
        int min = loc->val;
        while(loc->next) {
                loc = loc ->next;
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
int main() {
 MinStack* =  minStackCreate();
 minStackPush(MinStack,-2);
 minStackPush(MinStack,0);
 minStackPush(MinStack,-3);
 minStackPop();
 printf("the min is %d",minStackGetMin());
}

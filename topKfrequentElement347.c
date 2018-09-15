void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    quickSort(nums,0,numsSize-1);
    int map[numsSize][2];
    int i = 0 , prev = nums[0] , count = 0 , distinctN = 0 , j = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == prev) {
            map[distinctN][0] = prev;
            count++;
            map[distinctN][1] = count;
        } else {
            prev = nums[i];
            count = 1;
            distinctN++;
            map[distinctN][0] = prev;
            map[distinctN][1] = count;
        }
    }

    distinctN ++;
    
    int* ans = calloc( k  , sizeof(int) );
    int max = -1 , maxindex;
    for (i = 0; i < k ; i++) {
        max = -1;
        for (j = 0; j < distinctN;j++) {
            if (map[j][1] > max) {
                max = map[j][1];
                maxindex = j;
            }
        }
        ans[i] = map[maxindex][0];
        map[maxindex][1] = -1;
    }

    if (k > distinctN) {
        *returnSize = distinctN;
    } else {
        *returnSize = k; 
    }
    
    return ans;

}


//fatest method
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct node {
    int val;
    int count;
    struct node *next; // hash table
} NODE;

void swap(NODE **n1, NODE **n2) {
    NODE *tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

#define TSIZE (3000)
void insert_table(NODE **table, int key, int val, NODE **heap, int *hSize) {
    if (table[key]) {
        NODE *cur = table[key];
        while (cur->val != val) {
            cur = cur->next;
        }
        if (!cur) {
            NODE *n = calloc(1, sizeof(NODE));
            n->next = table[key];
            n->val = val;
            n->count = 1;
            table[key] = n;
            heap[*hSize] = n;
            ++*hSize;
        } else {
            cur->count++;
        }
    } else {
        NODE *n = calloc(1, sizeof(NODE));
        n->val = val;
        n->count = 1;
        table[key] = n;
        heap[*hSize] = n;
        ++*hSize;
    }
}

void insert_heap(NODE **heap, int idx) {
    int  cIdx = idx, pIdx = (cIdx - 1)/2;
    while (cIdx > 0) {
        if (heap[pIdx]->count < heap[cIdx]->count) {
            swap(&heap[pIdx], &heap[cIdx]);
            cIdx = pIdx;
            pIdx = (cIdx - 1)/2;
        } else {
            break;
        }
    }
}

void heapify(NODE **heap, int size, int idx) {
    int pidx = idx, lchild = 2 * pidx + 1, rchild = 2 * pidx + 2;
    if (rchild <= size) {
        if (heap[pidx]->count < heap[rchild]->count ||
           heap[pidx]->count < heap[lchild]->count) {
            if (heap[rchild]->count > heap[lchild]->count) {
                swap(&heap[pidx], &heap[rchild]);
                heapify(heap, size, rchild);
            } else {
                swap(&heap[pidx], &heap[lchild]);
                heapify(heap, size, lchild);
            }
        }
    } else if (lchild <= size) {
        if (heap[pidx]->count < heap[lchild]->count) {
            swap(&heap[pidx], &heap[lchild]);
            heapify(heap, size, lchild);
        }
    }
}

void del_max(NODE **heap, int *eIdx, int *res, int *size) {
    if (*eIdx < 0)
        return;
    res[*size] = heap[0]->val;
    ++*size;

    if (*eIdx == 0) {
        --*eIdx;
        return;
    }
    swap(&heap[0], &heap[*eIdx]);
    --*eIdx;
    int pIdx = 0;
    int lIdx, rIdx;
    while (pIdx <= *eIdx) {
        lIdx = 2 * pIdx + 1;
        rIdx = 2 * pIdx + 2;
        if (rIdx <= *eIdx) {
            if (heap[pIdx]->count < heap[lIdx]->count ||
               heap[pIdx]->count < heap[rIdx]->count) {
                if (heap[rIdx]->count > heap[lIdx]->count) {
                    swap(&heap[rIdx], &heap[pIdx]);
                    pIdx = rIdx;
                } else {
                    swap(&heap[lIdx], &heap[pIdx]);
                    pIdx = lIdx;
                }
            } else {
                break;
            }
        } else if (lIdx <= *eIdx) {
            if (heap[lIdx]->count > heap[pIdx]->count) {
                swap(&heap[lIdx], &heap[pIdx]);
                pIdx = lIdx;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    
}

void free_list(NODE *n) {
    if (n) {
        if (n->next)
            free_list(n->next);
        free(n);
    }
}

void free_table(NODE **table, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (table[i]) {
            free_list(table[i]);
        }
    }
    free(table);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    NODE **table;
    NODE **heap;
    int i, hSize;
    int *res = calloc(k, sizeof(int));
    *returnSize = 0;
    table = calloc(TSIZE, sizeof(NODE*));
    heap = calloc(numsSize, sizeof(NODE*));
    hSize = 0;
    for (i = 0; i < numsSize; i++) {
        int key = nums[i] % TSIZE;
        if (key < 0) {
            key = key + TSIZE;
        }
        insert_table(table, key, nums[i], heap, &hSize);
    }
#if 1
    if (hSize > 1) {
        for (i = (hSize - 2)/2; i >= 0; i--) {
            heapify(heap, hSize - 1, i);
        }
    }
#else
    for (i = 1; i < hSize; i++) {
        insert_heap(heap, i);
    }
#endif
    hSize--;
    for (i = 0; i < k; i++) {
        del_max(heap, &hSize, res, returnSize);
    }
    free(heap);
    free_table(table, TSIZE);
    return res;
}

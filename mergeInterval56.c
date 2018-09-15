//the fatest method
int partition(struct Interval* intervals, int s, int e){
    int mid = (s+e)/2;
    struct Interval temp = intervals[mid];
    intervals[mid] = intervals[e];
    intervals[e] = temp;
    
    int i = s, big = s;
    int left = temp.start;
    for (i = s; i < e; i++) {
        if (intervals[i].start < left) {
            struct Interval t = intervals[i];
            intervals[i] = intervals[big];
            intervals[big] = t;
            big++;
        }
    }
    intervals[e] = intervals[big];
    intervals[big] = temp;
    return big;
    
}
void sort(struct Interval* intervals, int s, int e) {
    if (s >= e) {
        return;
    }
    int div = partition(intervals, s, e);
    sort(intervals, s, div -1);
    sort(intervals, div + 1, e);
    return;
}
void mergeHelper(struct Interval* intervals, int s, int e, struct Interval* res, int* rSize){
    if (s > e) {
        return;
    }
    int i = s;
    int left = intervals[s].start;
    int right = intervals[s].end;
    for (i = s+1; i <= e; i++) {
        if (intervals[i].start <= right) {
            right = (intervals[i].end > right ? intervals[i].end : right);
        } else {
            break;
        }
    }
    res[*rSize].start = left;
    res[*rSize].end = right;
    (*rSize)++;
    
    return mergeHelper(intervals, i, e, res, rSize);
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    if (!intervals || intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    struct Interval* res = (struct Interval*)calloc(intervalsSize, sizeof(struct Interval));
    sort(intervals, 0, intervalsSize -1);
    mergeHelper(intervals, 0, intervalsSize - 1, res, returnSize);
    
    return res; 
}
//my method
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    struct Interval* ans = malloc(sizeof(struct Interval)*intervalsSize);bool back = false;
    for (int i = 0; i < intervalsSize; i++) {
        back = false;
        for (int j = i+1; j < intervalsSize; j++) {
            //printf("i = %d\n", i);
            if (intervals[j].end != -99 && intervals[j].start != -99) {
                if (intervals[i].end >= intervals[j].start && intervals[i].end < intervals[j].end && intervals[i].start < intervals[j].start) {
                    //ans[*returnSize].start = intervals[i].start;
                    //ans[*returnSize].end = intervals[j].end;
                    intervals[i].end = intervals[j].end;
                    //printf("1. %d , %d \n",intervals[i].start,intervals[i].end);
                    intervals[j].end = intervals[j].start = -99;
                    back = true;
                } else if (intervals[j].end >= intervals[i].start && intervals[j].end < intervals[i].end && intervals[j].start < intervals[i].start) {
                    //ans[*returnSize].start = intervals[j].start;
                    //ans[*returnSize].end = intervals[i].end;
                    intervals[i].start = intervals[j].start;
                    intervals[j].end = intervals[j].start = -99;
                    back = true;
                } else if (intervals[i].end > intervals[j].end && intervals[i].start < intervals[j].start) {
                    //ans[*returnSize].start = intervals[i].start;
                    //ans[*returnSize].end = intervals[i].end;
                    intervals[j].end = intervals[j].start = -99;
                    back = true;
                } else if (intervals[j].end > intervals[i].end && intervals[j].start < intervals[i].start) {
                    //ans[*returnSize].start = intervals[j].start;
                    //ans[*returnSize].end = intervals[j].end;
                    intervals[i].start = intervals[j].start;
                    intervals[i].end = intervals[j].end;
                    intervals[j].end = intervals[j].start = -99;
                    back = true;
                } else if (intervals[j].end == intervals[i].end && intervals[j].start == intervals[i].start) {
                    //ans[*returnSize].start = intervals[j].start;
                    //ans[*returnSize].end = intervals[j].end;
                    intervals[j].end = intervals[j].start = -99;
                    back = true;
                } else if (intervals[i].end < intervals[j].end && intervals[j].start == intervals[i].start) {
                    //ans[*returnSize].start = intervals[j].start;
                    //ans[*returnSize].end = intervals[j].end;
                    intervals[i].end = intervals[j].end;
                    intervals[j].end = intervals[j].start = -99;
                    back = true;
                } else if (intervals[i].end > intervals[j].end && intervals[j].start == intervals[i].start) {
                    //ans[*returnSize].start = intervals[j].start;
                    //ans[*returnSize].end = intervals[j].end;
                    intervals[j].end = intervals[i].end;
                    intervals[j].end = intervals[j].start = -99;
                    back = true;
                } else if (intervals[i].start < intervals[j].start && intervals[j].end == intervals[i].end) {
                    //ans[*returnSize].start = intervals[j].start;
                    //ans[*returnSize].end = intervals[j].end;
                    intervals[j].end = intervals[j].start = -99;
                    back = true;
                } else if (intervals[i].start > intervals[j].start && intervals[j].end == intervals[i].end) {
                    //ans[*returnSize].start = intervals[j].start;
                    //ans[*returnSize].end = intervals[j].end;
                    intervals[i].start = intervals[j].start;
                    intervals[j].end = intervals[j].start = -99;
                    back = true;
                }
                //printf(" %d , %d \n",intervals[i].start,intervals[i].end);
            }
        }
        if (back) {
            i--;
        }
    }
    *returnSize = 0;
    for (int i = 0; i < intervalsSize; i++) {
        //printf("count %d \n",i);
        if (intervals[i].start != -99 && intervals[i].end != -99) {
            ans[*returnSize].start = intervals[i].start;
            ans[*returnSize].end = intervals[i].end;
            *returnSize =*returnSize + 1;
            printf("%d , %d \n",intervals[i].start,intervals[i].end);
        }
        
    }
    return ans;
}

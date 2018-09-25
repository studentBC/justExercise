//the fatest method ... using radix sort
void
radixSort(int *a, int n) {
  int c[4][256] = {0};    /* 基数为256,对于32位整数来说,分为了4部分. */
  int *b;
  int i, j;

  for (j = 0; j < 4; ++j) {
    for (i = 0; i < n; ++i)
      ++c[j][a[i] >> (j * 8) & 0xFF];
  }

  for (j = 0; j < 4; ++j) {
    for (i = 1; i < 256; ++i)
      c[j][i] += c[j][i - 1];
  }

  b = malloc(n * sizeof(int));

  for (j = 0; j < 4; ++j) {
    for (i = n - 1; i >= 0; --i) {
      b[--c[j][a[i] >> (j * 8) & 0xFF]] = a[i];
    }
    int *temp = a;
    a = b;
    b = temp;
  }

  free(b);
}

int
longestConsecutive(int *nums, int numsSize) {
  int i, j, ans, consecutive;

  if (numsSize <= 1)
    return numsSize;

  /* 基数排序只能处理符号相同的数. */
  j = 0;
  for (i = 0; i < numsSize; ++i) {
    if (nums[i] >= 0)
      continue;
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    ++j;
  }

  if (j > 0)
    radixSort(nums, j);
  radixSort(nums + j, numsSize - j);

  ans =  consecutive = 1;
  for (i = 1; i < numsSize; ++i) {
    if (nums[i] == nums[i - 1] + 1)
      ++consecutive;
    else if (nums[i] > nums[i - 1] + 1)
      consecutive = 1;

    if (consecutive > ans)
      ans = consecutive;
  }

  return ans;
}
//my method
/* function to sort arr using shellSort */
int shellSort(int* arr, int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int count = 1, start = 1, max = 1 , i;
    shellSort(nums,numsSize);
    while (start < numsSize) {
        for (i = start; i < numsSize; i++) {
            if (nums[i] == nums[i-1]+1) {
                count++;
            } else if (nums[i] == nums[i-1]) {
                
            } else {
                break;
            }
        }
       // printf("count is %d \n",count);
        if (max < count) {
            max = count;
        }
        count = 1;
        start = i+1;
       // printf("start is %d \n",start);
    }
    return max;
}

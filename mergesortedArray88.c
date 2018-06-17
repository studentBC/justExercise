void merge(int* nums1, int m, int* nums2, int n) {
    int i = 0,j=0,count = 0,total = m+n-1;
    int cp1[m+1];
    for (i = 0; i < m;i++){
        cp1[i] = nums1[i];
    }
i=0;
    nums1[total] = -1;
    while (nums1[total] == -1) {
        if(i<m && j<n && cp1[i] < nums2[j]) {
            printf("%d \n",cp1[i]);
            nums1[count] = cp1[i]; 
            count++;
            i++;
        }else if(i<m && j>=n) {
            nums1[count] = cp1[i]; 
            count++;
            i++;
        }  else {
            nums1[count] = nums2[j];
            count++;
            j++;
        }
        
    }
    return;
}

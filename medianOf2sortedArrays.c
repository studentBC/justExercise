//the fatest method
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *p,t,l,r,mid,mid2,lmax,rmin;
    int lTotal=(nums1Size+nums2Size)/2;

    if ((nums1Size+nums2Size)%2 == 1)
        lTotal++;
    if (nums1Size>nums2Size)
    {
        t=nums1Size;
        nums1Size=nums2Size;
        nums2Size=t;
        p=nums1;
        nums1=nums2;
        nums2=p;
    }

    l=0;
    r=nums1Size-1;
    while (l<=r)
    {
        mid=(l+r)/2;
        mid2=lTotal-mid-2;
        if (mid==nums1Size-1 && nums1Size!=1)
            break;
        if (nums1Size!=1 && nums2[mid2]<=nums1[mid+1] && nums1[mid]<=nums2[mid2+1])
            break;
        else if (nums1[mid]>nums2[mid2+1])
            r=mid-1;
        else if (nums1Size!=1 && nums2[mid2]>nums1[mid+1])
            l=mid+1;
        else if (nums1Size==1)
            break;
    }

    if (nums1Size==0)
    {
        lmax=nums2[lTotal-1];
        if (nums2Size>1)
            rmin=nums2[lTotal];
    }
    else if (mid==nums1Size-1 && nums1Size!=1)
    {
        lmax=nums1[nums1Size-1];
        if (mid2!=-1 && nums2[mid2]>lmax)
            lmax=nums2[mid2];
        rmin=nums2[mid2+1];
    }
    else if (nums1Size!=1 && nums2[mid2]<=nums1[mid+1] && nums1[mid]<=nums2[mid2+1])
    {
        lmax=nums1[mid];
        if (nums2[mid2]>lmax)
            lmax=nums2[mid2];
        rmin=nums1[mid+1];
        if (nums2[mid2+1]<rmin)
            rmin=nums2[mid2+1];
    }
    else if (r==-1)
    {
        lmax=nums2[lTotal-1];
        rmin=nums1[0];
        if (lTotal<=nums2Size-1 && nums2[lTotal]<rmin)
            rmin=nums2[lTotal];
    }
    else if (nums1Size==1)
    {
        lmax=nums1[0];
        if(lTotal-2>=0 && nums2[lTotal-2]>lmax)
            lmax=nums2[lTotal-2];
        rmin=nums2[lTotal-1];
    }

    double dlmax=lmax,drmin=rmin;

    if ((nums1Size+nums2Size)%2 ==0)
        return (dlmax+drmin)/2;
    else
        return dlmax;
}
//my method
/* function to sort arr using shellSort */
int shellSort(int arr[], int n) 
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
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size+nums2Size;
    int temp[total];
    for (int i = 0; i < nums1Size; i++) {
        temp[i] = nums1[i];
    }
    for (int j = 0; j < nums2Size; j++) {
        temp[j+nums1Size] = nums2[j];
    }
    shellSort(temp,total);
    int mid = total/2;
    if (total%2 == 0) {
        return (double)(temp[mid] + temp[mid-1])/2;
    } else {
        return temp[total/2];
    }
}

//the fatest method
int hammingWeight(uint32_t n) {
    int count =0;
    
    while(n>0)
    {
        count+=n&1;
        n=n>>1;
    }
    return count;
}
//my method 
int hammingWeight(uint32_t n) {
    int i, count = 0;
    uint32_t lu = UINT_MAX;
    int totalsize = sizeof(uint32_t)*8;
    //printf("the size is %d \n",totalsize);
    for (i = 0; i<totalsize; i++) {
        if(n&1 == 1) {
            count++;
        }
        n=n>>1;
    }
    return count;
}

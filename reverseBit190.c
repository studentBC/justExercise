uint32_t reverseBits(uint32_t n) {
    uint32_t ans=0;
    int count = 31;
    //uint32_t leftisone = pow(2,31);
    while(n>0) {
         ans+=((n&1)*pow(2,count));
        n=n>>1;
        count--;
    }
    return ans;
}
//the fatest method
uint32_t reverseBits(uint32_t n) {
    uint32_t returnVal = 0;
    for(uint32_t i = 0; i < 32; i++)
    {
        returnVal = (returnVal|(((n&(1<<i))>>i)<<(31-i)));
    }
	
	return returnVal;
}
//my improved method and it will become the fatest
uint32_t reverseBits(uint32_t n) {
    uint32_t ans=0;
    int count = 31;
    //uint32_t leftisone = pow(2,31);
    while(n>0) {
         ans+=((n&1)<<count);
        n=n>>1;
        count--;
    }
    return ans;
}

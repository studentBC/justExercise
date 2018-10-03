int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int max = -1,benefit = 0,next,temp;
    for (int i = 0; i < gasSize; i++) {
        //printf("start from %d \n",i);
        benefit= gas[i] - cost[i];
        if (benefit >= 0) {
            for (int j = 0; j < costSize; j++) {
                next = (i+1+j);
                //printf("next is %d benefit is %d \n",next,benefit);
                if (next >= costSize) {
                    next-=costSize;
                }
                benefit += (gas[next] - cost[next]);
                //printf("after %d benefit is %d \n",next,benefit);
                if (benefit < 0) {
                    break;
                }
            }
            if (benefit >= 0) {
                return i;
            }
        }
    }
    return -1;
}
//the fatest method
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {

    int i;
    int sum = 0;
    int start = 0;
    int total = 0;
    for(i = 0 ; i < gasSize ; i++)
    {
       sum += gas[i] - cost[i];
       if(0 > sum)
       {
           start = i+1;
           total += sum;
           sum = 0;
       }
        
    }
    total += sum;
    return total < 0 ? -1 : start;
    
}

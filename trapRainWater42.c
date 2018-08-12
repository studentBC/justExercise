int trap(int* height, int heightSize) {
    int level,i , j, max = -1 , start, end, area = 0;
    bool right = false;
    for (i = 0; i < heightSize; i++) {
        if (max < height[i]) {
            max = height[i];
        }
    }
    //printf("max is %d   heightsize is %d \n",max,heightSize);
    for (level = 1; level <= max ; level++) {
        start = 1;
        //printf("level: %d\n",level);
        while(1) {
            for(j = start; j < heightSize ;j++) {
                if (height[j] < level && height[j-1] >= level ) {
                    start = j-1;
                    break;
                } else {
                    start = j;
                }
            } 
            //printf("start : %d",start);
            right = false;
            for(j = start; j < heightSize-1 ;j++) {
                if (height[j] < level && height[j+1] >= level ) {
                    end = j+1;
                    right = true;
                    break;
                } 
            }
            //printf("  end : %d \n",end); 
            
            if (end > start && right) {
                area+=(end-start-1);
                /*
                for (i = start+1;i<end;i++) {
                    height[i] = level;
                }
                */
                //printf("area: %d\n",area);
                start = end;
            } else {
                break;
            }
        }
    }
    return area;
}

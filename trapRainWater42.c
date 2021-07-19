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
//the fatest method
int trap(int* height, int heightSize) {
    
    int largest_l = 0, largest_r = 0, units = 0;
    int i =0,j =0;
    int *left = (int *)malloc(sizeof(int)*heightSize);
    int *right = (int *)malloc(sizeof(int)*heightSize);
    
    if (height == NULL)
        return 0;
    
    largest_l = height[0];
    largest_r = height[heightSize-1];
    for (i = 0,j = heightSize-1; i < heightSize; i++,j--)
    {
        largest_l = height[i] > largest_l? height[i] : largest_l;
        left[i] = largest_l - height[i] < 0 ? 0 : largest_l - height[i];       
        
        largest_r = height[j] > largest_r? height[j] : largest_r;
        right[j] = largest_r - height[j] < 0 ? 0 : largest_r - height[j];
    }
    
    for (i = 0; i < heightSize; i++)
    {
        units += right[i] > left[i] ? left[i] : right[i];
    }
    return units;
}
//my dp solutin
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size(), ans = 0, h;
        if (len == 0) return 0;
        vector<int>lm(len, 0), rm(len, 0);
        lm[0] = height[0];
        rm.back() = height.back();
        for (int i = 1; i < len; i++) lm[i] = max(lm[i-1], height[i]);
        len--;
        for (int i = len-1; i > -1; i--) rm[i] = max(rm[i+1], height[i]);
        for (int i = 1; i < len; i++) {
            h=min(lm[i-1], min(lm[i+1], rm[i+1]));
            if (h > height[i]) ans+=(h-height[i]);
        }
        return ans;
    }
};

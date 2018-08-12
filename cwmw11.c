//the fatest method which will lead left and right to find the larger height
int maxArea(int* height, int heightSize) {
    int left=0, right = heightSize-1, i, j;
    int area = 0, tmpArea;;
    while(left < right){
        i=left,j=right;
        tmpArea = (right-left)*(height[left]>height[right]?height[right]:height[left]);
        if(tmpArea>area) area=tmpArea;
        if(height[left]<height[right]) 
            left++;
        else 
            right--;
    }
    return area;
}
//my method
int maxArea(int* height, int heightSize) {
    int i ,j ,max = 0,area,high;
    for (i = 0; i < heightSize-1; i++) {
        for (j = i+1;j<heightSize ;j++) {
            if (height[i] < height[j]) {
                high = height[i];
            } else {
                high = height[j];
            }
            area = (j-i)*high;
            if (area > max) {
                max = area;
            }
        }
    }
    return max;
}

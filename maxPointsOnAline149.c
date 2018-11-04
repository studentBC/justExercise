void push (double** slope, double s, int* count, double distance) {
    for (int i = 0; i < *count; i++) {
        if (s == slope[i][0]) {
            slope[i][1]++;
            return;
        }
    }
    slope[*count][0] = s;
    slope[*count][1] = 1;
    slope[*count][2] = distance;
    *count = *count +1;
    return NULL;
}
int maxPoints(struct Point* points, int pointsSize) {
    double** slope = malloc(sizeof(double*)*pointsSize);
    for (int a = 0; a < pointsSize; a++) {
        slope[a] = calloc(3,sizeof(double));
    }

    if (pointsSize == 0) {
        return 0;
    } else if (pointsSize == 1) {
        return 1;
    }
    int* count = malloc(sizeof(int)) , max = 0, maxindex , sum, ans = 0;
    double intercept , m, temp;
    for (int i = 0; i < pointsSize; i++) {
        *count = 0;
        //initialize slope
        //printf("start:  %d , %d \n",points[i].x,points[i].y);
        for (int a = 0; a < pointsSize; a++) {
            slope[a][0] = slope[a][1] = 0;
        }
        for (int j = 0; j < pointsSize; j++) {
            //printf("to:  %d , %d \n",points[j].x,points[j].y);
            if (i!=j) {
                if (points[i].x == points[j].x) {
                    //printf("vertical line : slope is %lf and intercept is %lf \n",m,intercept);
                    push ( slope, INT_MAX, count, points[j].x);                
                } else if (points[i].y == points[j].y) {
                     //printf("horizon line : slope is %lf and intercept is %lf \n",m,intercept);
                     push ( slope, 0, count, points[j].y);
                }else {
                    //printf("i: ( %d , %d ) , j: ( %d , %d ) \n" ,points[i].x,points[i].y  ,  points[j].x,points[j].y);
                    m = (double)(points[i].y - points[j].y)/(double)(points[i].x - points[j].x);
                    intercept = (double)points[i].y - (double)(m*points[i].x);
                    //printf("y is %d , x is %d , slope is %lf and intercept is %lf \n", points[j].y , points[j].x ,m,intercept);
                    push ( slope, m,count, intercept );
                }
            }
        }

        //record the max count
        for (int k = 0; k < *count; k++) {
            //printf("count is %lf slope is %lf interpret is %lf \n",slope[k][1],slope[k][0],slope[k][2]);
            if (max < slope[k][1]) {
                max = slope[k][1];
                maxindex = k;
            }
        }
        sum = 0;
        //printf("max index is %d slope is %lf \n",maxindex,slope[maxindex][0]);
        if (slope[maxindex][0] == INT_MAX) {
            for (int b = 0; b < pointsSize; b++) {
                if (points[b].x == slope[maxindex][2]) {
                     sum++;
                }   
            }   
        } else if (slope[maxindex][0] == 0) {
             for (int b = 0; b < pointsSize; b++) {
                 if (points[b].y == slope[maxindex][2]) {
                      sum++;
                 }
             }  
         } else {
            for (int b = 0; b < pointsSize; b++) {
                //printf("( %d , %d )\n",points[b].x,points[b].y);
                temp = ((double)points[b].y -slope[maxindex][2])/slope[maxindex][0];
                //printf("temp is %lf \n",temp );
                double ans = (double)points[b].x - temp;
                //printf("ans is %lf \n",abs( (double)points[b].x - temp ));
                if (fabs( (double)points[b].x - temp ) < 0.0000001) {
                    sum++;
                }
            }
        }
        //printf("sum is %d \n",sum);
        if (sum > ans) {
            ans = sum; 
        }
    }
    return ans;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    bool carrier = true;
    for (int i = 0; i < digitsSize; i++){
        if(digits[i] != 9){
            carrier = false;
            break;
        } 
    }
    int* ans  = NULL;
    if (carrier) {
       ans = calloc( (digitsSize+1), sizeof(int));
        for (int i = 1; i <= digitsSize; i++){
            ans[i] = 0; 
        }
        ans[0] = 1;
        *returnSize = digitsSize+1;
        return ans;
    } else {
        ans = calloc( (digitsSize), sizeof(int));
        *returnSize = digitsSize;
    }

    int count = digitsSize-1;carrier = false;
    if (digits[count]!=9) {
        ans[count] = digits[count]+1;
    } else {
        ans[count] = 0;
        carrier = true;
    }
    for (int i = count-1; i >-1;i--) {
        if (digits[i] == 9 && carrier) {
            ans[i] = 0;
            carrier = true;
        } else if (digits[i] != 9 &&carrier) {           
            ans[i] = digits[i]+1;
            carrier = false;
        } else {
            ans[i] = digits[i];
        }
    }
    
        return ans;

}

class RLEIterator {
    
    ArrayList number = new ArrayList();
    public RLEIterator(int[] A) {
        for (int i = 0; i < A.length; i++) {
            number.add(A[i]);
        }
        return;
    }

    public int next(int n) {
        int prev = -1;
        while ( n > 0 && number.size() > 0) {
            if ((int)number.get(0) > n) {
                number.set(0, (int)number.get(0)-n);
                prev = (int)number.get(1);
                n = 0;
            } else if ((int)number.get(0) == n) {
                prev = (int)number.get(1);
                number.remove(0);
                number.remove(0);
                n = 0;
            } else {
                n-=(int)number.get(0);
                number.remove(0);
                number.remove(0);
            }
        }
        return prev;
    }

}
/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
//the fatest method
class RLEIterator {

    private int[] sequence;
    private int sizePointer;
    
    public RLEIterator(int[] A) {
        sequence = A;
        sizePointer = 0;
    }
    
    public int next(int n) {
        if(sizePointer >= sequence.length) return -1;
        if(n - sequence[sizePointer] < 0){
            sequence[sizePointer] -= n;
            return sequence[sizePointer+1];
        }else{
            int size = sequence[sizePointer];
            sequence[sizePointer] = 0;
            sizePointer += 2;
            if(n - size == 0) return sequence[sizePointer - 1];
            return next(n - size);
        }
    }
}

class Solution {
    public int atMostNGivenDigitSet(String[] D, int N) {
        int total = 0, temp = N, len = D.length, ans, count = 0;
        ArrayList<Integer> n = new ArrayList<Integer>();
        while (temp > 0) {
            n.add(temp%10);
            temp/=10;
            total++;
        }
        int[] target = new int[total];
        for (int i = total-1, j= 0; i > -1; --i,++j) {
            target[j] = n.get(i);
        }
        int[] num = new int[len];
        for (int i = 0; i < len; i++) {
            num[i] = D[i].charAt(0)-'0';
        }
        if (len > 1) {
            ans = (int)(Math.pow(len, total)-len)/(len-1);
        } else {
            ans = total-1;
            if (target[0] >= num[0])ans++;
            return ans;
        }
        int sum = 0, end = target.length-1;
        boolean found = true, outcome = true;
        for (int i = 0; i < end; ++i) {
            found = false;
            for (int j = 0; j < num.length; ++j) {
                if (target[i] > num[j]) {
                    sum+=Math.pow(num.length,(end-i));
                } else if (target[i] == num[j]) {
                    found = true;
                }
            }
            //System.out.println(sum);
            outcome = outcome & found;
            if(!found)break;
        }
        //System.out.println(ans);
        if (outcome) {
            for (int i = 0; i < num.length; ++i) {
                if (num[i] <= target[end]) sum++;
            }
        }
        return sum+ans;
    }
}
//the fatest method
class Solution {
    public int atMostNGivenDigitSet(String[] D, int N) {
        char[] digits = Integer.toString(N + 1).toCharArray();
        int l = digits.length, d = D.length;
        int res = 0;
        
        int[] nums = new int[d];
        
        for (int i = 0; i < d; i++) {
            nums[i] = Integer.valueOf(D[i]);
        }
        
        // for digits from 1 ~ l - 1;
        for (int i = 1; i <= l - 1; i++) {
            res += Math.pow(d, i);
        }

        // for numbers with l digits
        for (int i = 0; i < l; i++) {
            int h = 0;
            // how many digits < digits[]
            while (h < d && nums[h] < (digits[i] - '0')) {
                h++;
            }
            
            res += h * Math.pow(d, (l - i - 1));
            
            // already add all cases
            if (h == d) {
                break;
            }
            
            // no need to add the rest cases
            if (nums[h] != (digits[i] - '0')) {
                break;
            } 
            
            // // last number
            // if (i == l - 1) {
            //     res++;
            // }
        }
        return res;
    }
}


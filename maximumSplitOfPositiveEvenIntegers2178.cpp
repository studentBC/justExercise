/*
 So it's clear from question that if n is odd answer is not possible (bcz we can't represent a odd number as a sum of even numbers)

Now if n is even , then we have to make the largest list of unique even number such that the sum is equal to given n.

Now to make the largest we have to take smallest numbers first like 2,4,6,8... and so on.

but wait what happen if we are doing in this manner and the total sum is greater than desired , no worries , we wll do this step untill our sum is less than or equal to given number , and just add the remaining difference to last number in the list.

Take n =14

i = 2 , crSum = 0 , list = [] (crSum + 2 <= 14 , so push it) , crSum + i = 2 , list = [2]
i = 4 , crSum = 2 , list = [2] (crSum + 4 <= 14 , so push it) , crSum + i = 6 , list = [2,4]
i = 6 , crSum = 6 , list = [2,4] (crSum + 6 <= 14 , so push it) , crSum + i = 12 , list = [2,4,6]
i = 8 , crSum = 12 , list = [2,4,6] (crSum + 8 > 14 , so don't push it , break the loop)
Now we have crSum = 12 , and we want 14 , so simply add difference (which is 14-12 = 2 ) in the last element of list

so list = [2,4,6+(14-12)] = [2,4,8]
 */
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if (finalSum%2) return ans;
        long long s = 0;
        for (long long i = 2; i <= finalSum && s < finalSum; i+=2) {
            s+=i;
            ans.push_back(i);
        }
        if (s > finalSum) {
            s-=ans.back();
            ans.pop_back();
            ans.back()+=(finalSum-s);
        }
        return ans;
    }
};

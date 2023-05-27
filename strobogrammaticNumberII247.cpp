/*
Approach 1: Recursion
Intuition

Now, we know which digits can be used so let's try solving some sample cases.
We will try sample cases for NNN equals 111 up to NNN equals 444 which might be a bit lengthy, but by observing these sample cases, we should be able to come up with a recursive relation for this problem.

If the length of the number is 111:
The digit will remain at the same position and rotate 180°180 \degree180°.
Thus, the numbers can only be, 000, 111, and 888.


If the length is 222:
We have two positions (say indices 0 and 1), which will interchange.

So we can use,

Either two same digits which remain the same after rotation, 111111 and 888888.
Take note that we can't use 000 here because 000000 is not a 2 digit number. So we can't place 000 at the 0th0^{th}0 
th
  index of any number, except for the number 000 itself.

Or, two digits that change into one another, 696969 and 969696.

Thus, 2-digit strobogrammatic numbers will be, 111111, 696969, 888888, and 969696.


If the length is 333:
We have three positions (say indices 0, 1, and 2) and out of these three positions, index 0 and index 2 will interchange, but index 1 will remain in the same place.

Suppose we have all of the 1-digit strobogrammatic numbers. To find the 3-digit strobogrammatic numbers, we just need to append one extra digit at the beginning and at the end which are reversible. Here, reversible means it will keep the number strobogrammatic.
We know that we can use both types of digits (those that change into each other or remain the same after rotation) for this position. But keep in mind that we can't append 000 at the beginning.

=> '0' + (1-digit strobogrammatic numbers) + '0'
'0' + '0' + '0' = '000'  (1-digit number) (not valid)
'0' + '1' + '0' = '010' (2-digit number) (not valid)
'0' + '8' + '0' = '080' (2-digit number) (not valid)

=> '1' + (1-digit strobogrammatic numbers) + '1'
'1' + '0' + '1' = '101'
'1' + '1' + '1' = '111'
'1' + '8' + '1' = '181'

=> '6' + (1-digit strobogrammatic numbers) + '9'
'6' + '0' + '9' = '609'
'6' + '1' + '9' = '619'
'6' + '8' + '9' = '689'

=> '8' + (1-digit strobogrammatic numbers) + '8'
'8' + '0' + '8' = '808'
'8' + '1' + '8' = '818'
'8' + '8' + '8' = '888'

=> '9' + (1-digit strobogrammatic numbers) + '6'
'9' + '0' + '6' = '906'
'9' + '1' + '6' = '916'
'9' + '8' + '6' = '986'
Thus, these are all of the 3-digit strobogrammatic numbers: 101101101, 111111111, 181181181, 609609609, 619619619, 689689689, 808808808, 818818818, 888888888, 906906906, 916916916, and 986986986.


If the length is 444:
We have four positions (say indices 0, 1, 2, and 3), and out of these four positions, (index 0, index 3) and (index 1, index 2) will interchange.

Suppose we have all of the 2-digit strobogrammatic numbers. To find the 4-digit strobogrammatic numbers, we just need to append one extra digit at the beginning and the end which are reversible (just like previously discussed).

But here, in 2-digit strobogrammatic numbers, we can include 000000 because after appending a nonzero digit to the beginning and the end, '000000' becomes a valid 4-digit number.

=> '1' + (2-digit strobogrammatic numbers) + '1'
'1' + '00' + '1' = '1001'
'1' + '11' + '1' = '1111'
'1' + '69' + '1' = '1691'
'1' + '88' + '1' = '1881'
'1' + '96' + '1' = '1961'

=> '6' + (2-digit strobogrammatic numbers) + '9'
'6' + '00' + '9' = '6009'
'6' + '11' + '9' = '6119'
'6' + '69' + '9' = '6699'
'6' + '88' + '9' = '6889'
'6' + '96' + '9' = '6969'

=> '8' + (2-digit strobogrammatic numbers) + '8'
'8' + '00' + '8' = '8008'
'8' + '11' + '8' = '8118'
'8' + '69' + '8' = '8698'
'8' + '88' + '8' = '8888'
'8' + '96' + '8' = '8968'

=> '9' + (2-digit strobogrammatic numbers) + '6'
'9' + '00' + '6' = '9006'
'9' + '11' + '6' = '9116'
'9' + '69' + '6' = '9696'
'9' + '88' + '6' = '9886'
'9' + '96' + '6' = '9966'
Thus, 4-digit strobogrammatic numbers will be, 100110011001, 111111111111, 169116911691, 188118811881, 196119611961, 600960096009, 611961196119, 669966996699, 688968896889, 696969696969, 800880088008, 811881188118, 869886988698, 888888888888, 896889688968, 900690069006, 911691169116, 969696969696, 988698869886, and 996699669966.


Following this pattern, we can conclude that to find all strobogrammatic numbers with N-digits, we first need to find all strobogrammatic numbers with (N - 2) digits and then append reversible digits to the beginning and the end.

Now, instead of strobogrammatic numbers of length N, we need to find strobogrammatic numbers of length N - 2.
This is the same problem but with a smaller input. So we can approach this problem using recursion.

If you are not familiar with recursion, you can check out our Recursion Explore Card.

generateStroboNumbers(N) = List("digit1" + "number" + "digit2"
                                for each number in generateStroboNumbers(N - 2)
                                for each (digit1, digit2) in reversiblePairs
                               )
This will be our recursive logic, which is called as recurrence relation.

Now, to terminate the recursive calls, we need to think about base cases. A base case is some input for which we can determine the result without making further recursive calls.
With each recursive call, we decrease NNN by 222. Therefore, if NNN is initially even, we will make recursive calls until NNN is 000. Otherwise, if NNN is odd, we will make recursive calls until NNN is 111.
We can determine the result for input N=0N = 0N=0 and input N=1N = 1N=1 without using recursion (as shown above). Thus, we can make our base cases generateStroboNumbers(0) = [''] and generateStroboNumbers(1) = ['0', '1', '8'].

And the empty string can be considered as a 0-digit strobogrammatic number.

Note: We need to take N == 0 as our base case, not N == 2, because 2-digit numbers will not consider '00' as a valid number. Thus, if we generate 4-digit numbers using N == 2 as the base case, we will skip some numbers. However, if we start with N == 0, we will have an option to generate '00' as a valid number because we know the current position is not the first digit of the 4-digit number, so we can append 0.

Algorithm

Initialize a data structure reversiblePairs, which contains all pairs of reversible digits.

Call and return the recursive function, generateStroboNumbers(n, finalLength), where the first argument indicates that the current call will generate all n-digit strobogrammatic numbers. The second argument indicates the length of the final strobogrammatic numbers that we will generate and will be used to check if we can add '0' to the beginning and end of a number.

Create a function generateStroboNumbers(n, finalLength) which will return all strobogrammatic numbers of n-digits:

Check for base cases, if n == 0 return an array with an empty string [""], otherwise if n == 1 return ["0", "1", "8"].
Call generateStroboNumbers(n - 2, finalLength) to get all the strobogrammatic numbers of (n-2) digits and store them in subAns.
Initialize an empty array currStroboNums to store strobogrammatic numbers of n-digits.
For each number in prevStroboNums we append all reversiblePairs at the beginning and the end except when the current reversible pair is '00' and n == finalLength (because we can't append '0' at the beginning of a number) and push this new number in ans.
At the end of the function, return all the strobogrammatic numbers, i.e. currStroboNums.
*/

class Solution {
public:
    vector<vector<char>> reversiblePairs = {
        {'0', '0'}, {'1', '1'},
        {'6', '9'}, {'8', '8'}, {'9', '6'}
    };

    vector<string> generateStroboNumbers(int n, int finalLength) {
        if (n == 0) {
            // 0-digit strobogrammatic number is an empty string.
            return { "" };
        }

        if (n == 1) {
            // 1-digit strobogrammatic numbers.
            return { "0", "1", "8" };
        }

        vector<string> prevStroboNums = generateStroboNumbers(n - 2, finalLength);
        vector<string> currStroboNums;

        for (string& prevStroboNum : prevStroboNums) {
            for (vector<char>& pair : reversiblePairs) {
                // We can only append 0's if it is not first digit.
                if (pair[0] != '0' || n != finalLength) {
                    currStroboNums.push_back(pair[0] + prevStroboNum + pair[1]);
                }
            }
        }

        return currStroboNums;
    }

    vector<string> findStrobogrammatic(int n) {
        return generateStroboNumbers(n, n);
    }
};

class Solution {
public:
    vector<vector<char>> nums = {
        {'0', '0'}, {'1', '1'},
        {'6', '9'}, {'8', '8'}, {'9', '6'}
    };
    vector<string> findStrobogrammatic(int n) {
        queue<string>q;
        int count = 0;
        if (n%2 == 0) {
            count = 0;
            q.push("");
        } else {
            count = 1;
            q.push("0");
            q.push("1");
            q.push("8");
        }
        while (count < n) {
            count+=2;
            string num;
            for (int i = q.size(); i > 0; i--) {
                num = q.front();
                q.pop();
                for (auto& it: nums) {
                    if (count != n || it[0] != '0') {
                        q.push(it[0]+num+it[1]);
                    }
                }
            }
        }
        vector<string>ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

/*
In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

    Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
    Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.

Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

 

Example 1:

Input: [1,2,1]
Output: 3
Explanation: We can collect [1,2,1].

Example 2:

Input: [0,1,2,2]
Output: 3
Explanation: We can collect [1,2,2].
If we started at the first tree, we would only collect [0, 1].

Example 3:

Input: [1,2,3,2,2]
Output: 4
Explanation: We can collect [2,3,2,2].
If we started at the first tree, we would only collect [1, 2].

Example 4:

Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
Explanation: We can collect [1,2,1,1,2].
If we started at the first tree or the eighth tree, we would only collect 4 fruits.

 

Note:

    1 <= tree.length <= 40000
    0 <= tree[i] < tree.length
*/
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int type[2]; type[0] = type[1] = -1;
        int i = 0, left = 0, count = 2, ans = 0;
        while (i < tree.size()) {
            if (count) {
                if (type[0] != tree[i] && type[1] != tree[i]) {
                    if (type[0] < 0) {
                        type[0] = tree[i];
                    } else if (type[1] < 0) {
                        type[1] = tree[i];
                    }
                    count--;
                }
            } else {
                if (tree[i] != type[0] && tree[i] != type[1]) {
                    type[0] = INT_MAX;
                    for (int j = i-1; j >= left; j--) {
                        if (type[0] == INT_MAX && tree[j]!=tree[i]) {
                            type[0] = tree[j];
                            type[1] = tree[i];
                        } else if (tree[j] != type[0]) {
                            left = j+1;
                        }
                    }
                }
            }
            ans = max (ans, i-left+1);
            i++;
        }
        return ans;
    }
};
//the fatest method
static int x = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int currentTotal = 0, type1 = -1, type2 = -1, count_type2 = 0, ans = 0;
        
        for (int currentFruit: tree) {
            currentTotal = (currentFruit == type1 || currentFruit == type2) ? currentTotal + 1 : count_type2 + 1;
            if (currentFruit == type2) 
                count_type2 += 1;
            else {
                count_type2 = 1;
                type1 = type2;
                type2 = currentFruit;
            }
            ans = max(ans, currentTotal);
        }
        return ans;
    }
};

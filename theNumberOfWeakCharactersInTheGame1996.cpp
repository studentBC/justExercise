/*
Consider a simpler problem, where we only have one parameter say the attack value. In this case, all the characters except the one with the highest attack value will be weak. Hence, the number of weak characters will be the total characters minus the count of characters with the highest attack value. An alternative approach will be: we could sort the array in ascending order and then we can iterate over the array from the right end keeping the maximum attack value we have achieved so far. If this value is more than the current value then the character is weak.

We need to do something similar here, the only difference is we have two parameters. Let's sort these pairs in ascending order of their first value (attack). This way we will only need to take care of the second value (defense) because the character at a smaller index will not be stronger (i.e., will have a weaker attack value) than the character at a greater index.

Now once we have the array sorted in ascending order of their attack value, we can iterate over the pairs from right to left keeping the maximum defense value achieved so far. If this maximum defense value is more than the defense value at the current index then it's a weak character.

The above-mentioned theory has a catch. Consider the list of pairs [(1, 2), (3, 4), (3, 6), (3, 7)], the pairs are sorted in ascending order of their attack value and in ascending order of defense value in case of a tie in the attack values. When we iterate from the right end the maximum defense value will be equal to 7 when we reach the pair (3, 6), and we will consider this pair to be weak. Although, it's not as the attack value is equal and not strictly greater. The point to note here is, that we need to ignore the defense value of the pairs with the same attack value.

We can achieve it by sorting the pairs by ascending order of their attack value and then in descending order of their defense value in case of a tie. This way, the above list would be [(1, 2), (3, 7), (3, 6), (3, 4)] and hence when we iterate over it from the right end, the maximum defense value will be equal to 4 when we reach the pair (3, 6). We can take another example [(1, 1), (2, 1), (2, 2), (1, 2)], after sorting the pairs in ascending order of attack and in ascending order of defense in case of a tie will be [(1, 1), (1, 2), (2, 1), (2, 2)], now when we will iterate it from right to left the maximum defense value will be 2 when we reach the pair (2, 1), this will lead us to conclude that the pair (2, 1) is weak but it's not. On the other hand, sorting the pairs with the same attack value will produce [(1, 2), (1, 1), (2, 2), (2, 1)] and hence we will not face the previously mentioned issue here.

Algorithm

Sort the list of pairs properties in ascending order of their attack and then in descending order of the defense value. We can achieve it using the custom comparator.

Initialize the maximum defense value achieved maxDefense to 0.

Iterate over the pairs from right to left and for each pair:

a. If the maxDefense is greater than the defense value of the current character, increment the value weakCharacters.

b. Update the value of maxDefense if it's smaller than the current defense value.

Return weakCharacters.
*/
class Solution {
public:
    static bool compare (vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), compare);
        int ans = 0, atk, def;
        atk = properties.back()[0];
        def = properties.back()[1];
        for (int i = properties.size()-2; i > -1; i--) {
            if (properties[i][0] < atk && properties[i][1] < def) ans++;
            def = max(def,  properties[i][1]);
        }
        return ans;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getFreq(TreeNode* node , int& sum , map<int,int>&frequency) {
        if (!node)return;
        sum+=node->val;
        getFreq (node->left, sum, frequency);
        getFreq (node->right, sum, frequency);
        return;
    }
    void go (TreeNode* node, int& sum,  map<int,int>&frequency) {
        if (!node)return;
        sum = 0;
        getFreq(node , sum , frequency);
        map<int,int>::iterator it= frequency.find(sum);
        if ( it == frequency.end()) {
            frequency.insert(pair<int,int>(sum,1));
        } else {
            it->second++;
        }
        go (node->left, sum, frequency);
        go (node->right, sum, frequency);
        return;
    }
    vector<int>findFrequentTreeSum(TreeNode* root) {
        map<int,int>frequency;
        int sum = 0;
        go (root, sum, frequency);
        int max = 0;
        for (auto it = frequency.begin(); it!=frequency.end(); it++) {
            if (it->second > max) {
                max = it->second;
            }
        }
        vector<int>ans;
        for (auto it = frequency.begin(); it!=frequency.end(); it++) {
            if (it->second == max) {
                ans.push_back( it->first);
            }
        }
        return ans;
    }

};
//the fatest method
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int getSum(TreeNode *root, unordered_map<int, int>&freq) {
        if (root == NULL) return 0;
        int left_sum = getSum(root->left, freq);
        int right_sum = getSum(root->right, freq);
        int sum = left_sum+right_sum+ root->val;
        freq[sum]++;
        return sum;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq;
        getSum(root, freq);
        int max_freq = INT_MIN;
        for (auto e : freq) {
            max_freq = max(max_freq, e.second);
        }
        vector<int> result;
        for (auto e : freq){
            if (e.second == max_freq) result.push_back(e.first);
        }
        return result;
        
    }
};

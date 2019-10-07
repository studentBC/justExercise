class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    }; 

    void go (TreeNode* node, int sum, int& ans) {
        if (!node) return;
        sum+=node->val;
        if (node->left == NULL && node->right == NULL) ans+=sum;
        go (node->left, sum, ans);
        go (node->right, sum, ans);
    }
    int pathSum(vector<int>& nums) { 
        if (nums.size() == 0) return 0;
        TreeNode* root= new TreeNode(nums[0]%10);
        unordered_map<int, unordered_map<int, TreeNode*>>pos;
        pos[1][1] = root;
        int height, level;
        for (int i = 1; i < nums.size(); i++) {
            height = nums[i]/100-1;
            level = (nums[i]/10)%10;
            if (level%2) {
                level = (level+1)/2;
                pos[height][level]->left = new TreeNode(nums[i]%10);
                pos[height+1][level*2-1] = pos[height][level]->left;
            } else {
                pos[height][level/2]->right = new TreeNode(nums[i]%10);
                pos[height+1][level] = pos[height][level/2]->right;
            }
        }
        int ans = 0;
        go (root, 0, ans);
        return ans;
    }

};

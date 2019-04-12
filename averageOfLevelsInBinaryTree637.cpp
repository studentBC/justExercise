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
    void go (TreeNode* node, int curlevel, vector<vector<double>>& record) {
        if (!node) return;
        record[curlevel][0]++;
        record[curlevel][1] = node->val;
		curlevel++;
        go (node->left, curlevel, record);
        go (node->right, curlevel, record);
    }
    void getlevel (TreeNode* node, int curlevel, int& level) {
        if (!node) return;
        curlevel++;
        if (curlevel > level) level = curlevel;
        getlevel(node->left, curlevel, level);
        getlevel(node->right, curlevel, level);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        int level = 0;
        getlevel (root,0,level);
        cout << "total level " << level << endl;
        vector<vector<double>>record(level, vector<double>(2,0)); // the first one is count the second one is sum
        go (root,0,record);
        vector<double>ans;
        for (int i = 0; i < level; i++) {
            ans.push_back(record[i][1]/record[i][0]);
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        long long curLvl = 1;
        long long delimiter = curLvl;
        long long nextLvl = 0;
        long long sum = 0;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();

            q.pop();
            sum += node->val;
            --curLvl;

            if (node->left)
            {
                q.push(node->left);
                ++nextLvl;
            }
            if (node->right)
            {
                q.push(node->right);
                ++nextLvl;
            }

            if (curLvl == 0)
            {
                res.push_back((double)sum / delimiter);
                delimiter = curLvl = nextLvl;
                sum = nextLvl = 0;
            }
        }
        return res;
    }
};

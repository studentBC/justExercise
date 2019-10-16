class Solution {
public:
    void go (TreeNode* node, double target, int k, vector<int>& ans) {
        if (!node) return;
        double diff = abs(target-node->val);
        //cout << node->val <<" diff: " << diff << endl;
        if (ans.size() >= k) {
            double big = 0, dif;
            int index = -1;
            for (int i = 0; i < ans.size(); i++) {
                dif = abs((double)ans[i]-target);
                if (big < dif) {
                    big = dif;
                    index = i;
                }  
            }
            if (big > diff) {
                ans.erase(ans.begin()+index);
                ans.emplace_back(node->val);
            }
        } else {
            ans.emplace_back(node->val);
        }
        /*
        cout << endl;
        for (int i: ans) cout <<i <<" , ";
        cout << endl;
*/
        go (node->left, target, k, ans);
        go (node->right, target, k, ans);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int>ans;
        go (root, target, k, ans);
        return ans;
    }
};
//the fatest solution
class Solution {
    
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if(root == NULL)
            return {};
        deque<int>res;
        bool done = false;
        findSol(root, target, k, res, done);
        vector<int> ret(res.begin(), res.end());
        return ret;
    }
    
    void findSol(TreeNode* root, double target, int k, deque<int> &res, bool done)
    {
        if(root == NULL || done)
            return;
        findSol(root->left, target, k, res, done);
        res.push_back(root->val);
        int n = res.size();
        if (n > k) {
            if (abs(res.back() - target) <= abs(res.front() - target)) {
                res.pop_front();
            } else {
                res.pop_back();
                done = true;
            }
        }
     findSol(root->right, target, k, res, done);

    }
    
};

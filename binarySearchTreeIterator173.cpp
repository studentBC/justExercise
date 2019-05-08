/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    void go (TreeNode* node, std::priority_queue<int, std::vector<int>, std::greater<int> >& pq) {
        if (!node) return;
        pq.push(node->val);
        go (node->left,pq);
        go (node->right,pq);
    }
    BSTIterator(TreeNode* root) {
        go (root,pq);
    }
    
    /** @return the next smallest number */
    int next() {
        int temp = pq.top();
        pq.pop();
        return temp;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !pq.empty();
    }
private:
    std::priority_queue<int, std::vector<int>, std::greater<int> >pq;
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
//the fateset method
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private: 
    TreeNode *visit; 
    stack<TreeNode *> st; 
public:
    BSTIterator(TreeNode* root) {
        visit = root; 
    }
    
    /** @return the next smallest number */
    int next() {
        while (visit != NULL) {
            st.push(visit); 
            visit = visit->left; 
        }
        TreeNode* nxt = st.top(); 
        st.pop();
        visit = nxt->right; 
        return nxt->val; 
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return visit != NULL || st.size() > 0; 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

static const int _ = []() { ios::sync_with_stdio(false); cin.tie(NULL);return 0; }();

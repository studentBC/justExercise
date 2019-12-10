/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    void go (Node* node, vector<int>& temp) {
        if (!node) return;
        go (node->left, temp);
        temp.push_back(node->val);
        go (node->right, temp);
    }
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        vector<int>temp;
        go (root, temp);
        Node* ans = new Node();
        ans->val = temp[0];
        Node* prev = ans;
        //int end = temp.size()-1;
        for (int i = 1; i< temp.size(); i++) {
            Node* ptr = new Node();
            ptr->val = temp[i];
            ptr->left = prev;
            prev->right = ptr;
            prev = prev->right;
        }
        ans->left = prev;
        prev->right = ans;
        return ans;
    }
};
//the fatest solution
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        inorder(root);
        pre_->right = head_;
        head_->left = pre_;
        return head_;
    }
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        if (!head_) {
            head_ = node;
            pre_ = node;
        } else {
            pre_->right = node;
            node->left = pre_;
            pre_ = node;
        }
        inorder(node->right);
    }
private:
    Node *head_ = NULL;
    Node *pre_ = NULL;
};

class Solution2 { // circular double link list
public:
    Node* treeToDoublyList(Node* root) {
        Node *head = NULL;
        Node *p = head;
        if(!root)
            return head;
        stack<Node*> sk;
        while(!sk.empty() || root) {
            while(root) {
                sk.push(root);
                root = root->left;
            }
            Node *cur = sk.top();
            sk.pop();
            if(!head) {
                head = cur;
                p = head;
            } else {
                p->right = cur;
                cur->left = p;
                p = p->right;
            }
            root = cur->right;
        }
        head->left = p; // build circle.
        p->right = head; // 
        return head;
    }
};

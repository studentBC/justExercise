class Codec {
public:
    void go (TreeNode* node, string& serial) {
        if (!node) {
            serial+="# ";
            return;
        }
        serial+=(to_string(node->val)+" ");
        go (node->left,serial);
        go (node->right,serial);
        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string serial = "";
        go (root, serial);
        //cout << serial << endl;
        return serial;
    }
    void construct (TreeNode** node, istringstream& datas) {
        string number;
        datas >> number;
        if (number == "#") {
            *node = NULL;
            return ;
        }
        //ut << number << " , ";
        *node = new TreeNode (stoi(number));
        TreeNode** next; 
        next= &((*node)->left);
        construct(next, datas);
        next = &((*node)->right);
        construct(next, datas);
        return;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode** node;
        TreeNode* root;
        node = &root;
        istringstream datas(data);
        construct(node, datas);
        return root;
    }
};


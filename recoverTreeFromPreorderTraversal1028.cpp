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
    void construct (TreeNode** node, queue<string>& datas, int level) {
        if (!datas.empty()) {
            string number = datas.front();
            if (number[0] == '-') {
                if (number.size() != level) {
                    *node = NULL;
                    return ;
                } else if (number.size() == level) {
                    datas.pop();
                    //cout << "prepare to new " << datas.front() << endl;
                    *node = new TreeNode (stoi(datas.front()));
                    datas.pop();
                }
            } else if (level == 0) {
                *node = new TreeNode (stoi(number));
                datas.pop();
            }
            construct(&((*node)->left), datas,level+1);
            construct(&((*node)->right), datas,level+1);
        }
        return;
    }
    TreeNode* recoverFromPreorder(string S) {
        TreeNode** node;
        TreeNode* root;
        node = &root;
        string temp = "";
        for (int i = 0; i < S.size(); i++) {
            temp+=S[i];
            if (S[i+1] == '-' && S[i]!='-') {
                temp+=" ";
            } else if (S[i] == '-' && S[i+1]!='-'){
                temp+=" ";
            }
        }
        //cout << temp << endl;
        istringstream datas(temp);
        queue<string>data;
        while (datas >> temp) {
            //cout <<"push " << temp << endl;
            data.push(temp);
        }
        construct(node, data,0);
        return root;
    }
};


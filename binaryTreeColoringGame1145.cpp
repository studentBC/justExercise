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
    void go (TreeNode* node, int x, TreeNode* p, TreeNode*& parent, TreeNode*& left, TreeNode*& right) {
        if (!node)return;
        if (node->val == x) {
            parent = p;
            if (node->left) left = node->left;
            if (node->right) right = node->right;
        }  
        go (node->left, x, node, parent, left, right);
        go (node->right, x, node, parent, left, right);
    }
    void count (TreeNode* node, int& c) {
        if (!node) return;
        c++;
        count(node->left, c);
        count(node->right, c);
    }
	void Go (TreeNode* node, int x, int&  count) {
        if (!node || node->val == x)return;
			count++;
        Go (node->left, x, count);
        Go (node->right, x, count);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int ans = 0;
        TreeNode* parent = nullptr, *left = nullptr, *right = nullptr;
        int cp = 0, cl = 0, cr = 0;
        go (root,x, nullptr, parent, left, right);
        if (left) count (left, cl);
        if (right) count (right, cr);
		Go (root, x, cp);
		cout << cp <<" , " << cr <<" , " << cl << endl;
        if (cp > cl+cr+1) {
            return true;
        } else if (cl > cp+cr+1) {
            return true;
        } else if (cr > cp+cl+1) {
            return true;
        } else {
            return false;
        }
    }
};
//the fatest method
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
 public:
  bool SecondMustWin = false;

  int countKids(TreeNode *node) {
    if (node == NULL) {
      return 0;
    }

    return countKids(node->left) + countKids(node->right) + 1;
  }

  void calculate(TreeNode *node, int total) {
    int left = countKids(node->left);
    int right = countKids(node->right);

    int count = 1 + left + right;
    int remain = total - count;

    if (left + right < remain || remain + left < right
        || remain + right < left) {
      SecondMustWin = true;
    }
  }

  void preOrder(TreeNode *node, int current, int total) {
    if (node == NULL) {
      return;
    }

    if (node->val == current) {
      calculate(node, total);
    }

    preOrder(node->left, current, total);
    preOrder(node->right, current, total);
  }

  bool btreeGameWinningMove(TreeNode *root, int n, int x) {
    preOrder(root, x, n);

    return SecondMustWin;
  }
};

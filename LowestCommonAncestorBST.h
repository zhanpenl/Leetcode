#ifndef LCA_H
#define LCA_H

#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class LCA { // any other alternative solution: using stack, using less time

public:
	// should be a more efficient way, beat only 13.76%
	// ignored the fact that the tree is not only a Binary Tree but a BST !!!
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* commonAncestor = NULL;
		bool isFinished = false;
		isAncestor(root, p, q, commonAncestor, isFinished);
		return commonAncestor;
	}

private:
    bool isAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* & LCA, bool& isFinished) {
		// if have found the LCA, no need to do any recurrsion, which consume time
		if ( isFinished ) return false;
		// base case:
		if ( root == NULL ) return false;
		// store the values as integers and sum them up
		// std::cout << "current node: " << root->val << std::endl;
		int isLeftAnc = isAncestor(root->left, p, q, LCA, isFinished); 
		int isRightAnc = isAncestor(root->right, p, q, LCA, isFinished);
		int isRootAnc = root->val == p->val || root->val == q->val;
		if ( isLeftAnc + isRightAnc + isRootAnc == 2  ) {
			LCA = root;
			isFinished = true;
			return true;
		}
		return isLeftAnc || isRightAnc || isDirAnc(root, p) || isDirAnc(root, q);
	}

	// whether the node itself or its children contain m

	bool isDirAnc(TreeNode* root, TreeNode* m) {
		bool inLeft = root->left == NULL ? false : root->left->val == m->val;
		bool inRight = root->right == NULL ? false : root->right->val == m->val;
		return (root->val == m->val) || inLeft || inRight;
	}

};

#endif
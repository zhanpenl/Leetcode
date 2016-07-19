#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include "LowestCommonAncestorBST.h"
#include "MergeTwoSortedLists.h"

using namespace std;

TreeNode* createBST(const vector<double>& vec, int n) {
	// base case
	if ( n > vec.size() - 1 ) return NULL;
	// recurssion
	if ( !isnan(vec[n]) ) {
		TreeNode* root = new TreeNode((int) vec[n]);
		root->left = createBST(vec, 2 * n + 1);
		root->right = createBST(vec, 2 * n + 2);
		return root;
	}
	else return NULL;
}

void deleteBST(TreeNode* root) {
	// base case
	if ( root = NULL ) return;
	
	deleteBST(root->left);
	deleteBST(root->right);
	delete root;
}


int main(int argc, char **argv)
{
	double a[] = {5,3,6,2,4,NAN,NAN,1}; // 
	vector<double> v(a, a + sizeof(a) / sizeof(double));
	TreeNode* tree = createBST(v, 0);
//	cout << tree->val << endl << tree->left->val 
//		<< endl << tree->right->val << endl << tree->left->left->val << endl;

	LCA lca;
	TreeNode* test = lca.lowestCommonAncestor(tree, tree->left->left->left, tree->right);
	cout << "tree:" << tree << endl << "test:" << test << endl << "left:" << tree->left << endl;
	cout << "the ancestor is the node with: " << test->val << endl;
	return 0;
}

#include <bits/stdc++.h> 
/*
	Tree Node class.

	class BinaryTreeNode 
	{
		T data;
		BinaryTreeNode<T> *left;
		BinaryTreeNode<T> *right;

		BinaryTreeNode(T data) {
			this->data = data;
			left = NULL;
			right = NULL;
		}
	}
*/

void dfs(BinaryTreeNode<int>* root,int lvl,int &prevlvl,int &data,bool isleft){
	if(root==NULL) return;
	if(root->left == NULL && root->right==NULL && isleft){
		
		if(prevlvl<lvl || (prevlvl==lvl && data<root->data)) prevlvl = lvl,data = root->data;
		return;
	}
	dfs(root->left,lvl+1,prevlvl,data,true);
	dfs(root->right,lvl+1,prevlvl,data,false);
}
int deepestLeftLeafNode(BinaryTreeNode<int>* root)
{	if((root->left == NULL && root->right==NULL) || root==NULL) return 0;
	int data = 0;
    int prevlvl= -1;
	dfs(root,0,prevlvl,data,false);
    // Write your code here.
	return data;
}

#include<bits/stdc++.h>
using namespace  std;
class node{
  public:
  int val;
  node *left;
  node *right;
  node(){
    val = 0;
    left = NULL;
    right = NULL;
  }
  node(int data){
    val = data;
    left = NULL;
    right = NULL;
  }
};
class BST{
    public:
    node *root = new node();
    BST(){
        root = NULL;
    }
    bool isTree_empty(){
        if(root==NULL){
            return true;
        }
        else
           return false;
    }
    void preorder(node *temp){
         if(temp == NULL) return;
         cout<<temp->val<<" ";
         preorder(temp->left);
         preorder(temp->right);
    }
    void inorder(node *temp){
        if(temp == NULL)    return;
        inorder(temp->left);
        cout<<temp->val<<" ";
        inorder(temp->right);
    }
    void postorder(node *temp){
        if(temp == NULL)    return;
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->val<<" ";
    }
};
class Solution{
    private:
    bool func(node *root){
        if(root==NULL || (!root->right and !root->left)) return true;
        int leftdata = (root->left)?(root->left->val):0;
        int rightdata = (root->right)?(root->right->val):0;
        return (root->val==leftdata+rightdata && func(root->left) && func(root->right));
    }
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(node *root)
    {   return func(root);
    }
};
int main(){
    BST obj;
    node *n1 = new node(10);
    node *n2 = new node(9);
    node *n3 = new node(1);
    node *n4 = new node(4);
    node *n5 = new node(5);
    n2->left = n4;
    n2->right = n5;
    n1->left = n2;
    n1->right = n3; 
    Solution obj1;
    // obj.create_node(19);
    // obj.preorder(n1);
    cout<<obj1.isSumProperty(n1);
}
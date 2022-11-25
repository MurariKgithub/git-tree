#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
    int val;
    Node *left;
    Node* right;
    Node(int data){
        int val=data;
        Node* left = NULL;
        Node* right = NULL;
    }
};
class BST{
    private:
    void left_edge_call(Node *root,vector<int>& ans){
        if(root==NULL ||(root->left==NULL && root->right==NULL)) return;
        ans.push_back(root->val);
        //pre-order Traversal 
        if(root->left!=NULL) left_edge_call(root->left,ans);
        else left_edge_call(root->right,ans);
    }
    void right_edge_call(Node *root,vector<int>& ans){
        if(root==NULL ||(root->left==NULL && root->right==NULL)) return;
        //pre-order Traversal 
        if(root->right!=NULL) left_edge_call(root->right,ans);
        else left_edge_call(root->left,ans);
        ans.push_back(root->val);
    }
    void leaf_node_call(Node *root,vector<int>& ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){ 
        ans.push_back(root->val);
        }
        leaf_node_call(root->left,ans);
        leaf_node_call(root->right,ans);
    }
    public:
    //Node *root = new Node();
    void Solve(Node *root){
        vector<int> ans;
        ans.push_back(root->val);
        left_edge_call(root->left,ans);
        leaf_node_call(root,ans);
        right_edge_call(root->right,ans);
        cout<<endl;
        for (auto it:ans)
        { cout<<it<<" ";
        }
    }
};
int main(){
    Node *n1 = new Node(1);
    n1->val =1;
    // cout<<n1->val<<endl;
    Node *n2 = new Node(2);
    n2->val = 2;
    Node *n3 = new Node(3);
    n3->val = 3;
    Node *n4 = new Node(4);
    n4->val = 4;
    Node *n5 = new Node(5);
    n5->val = 5;
    Node *n6 = new Node(6);
    n6->val = 6;
    Node *n7 = new Node(7);
    n7->val=7;
    Node *n8 = new Node(8);
    n8->val = 8;
    Node *n9 = new Node(9);
    n9->val = 9;
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n5->left = n8;
    n5->right = n9;
    n3->left = n6;
    n3->right =n7;
    BST obj;
    obj.Solve(n1);
    // cout<<n1->val;
}
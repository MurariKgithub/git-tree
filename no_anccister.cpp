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
    void noSiblings(Node *root,vector<int>& ans){
        if(root==NULL) return;
        if(!root->left && root->right) ans.push_back(root->val);
        if(!root->right && root->left) ans.push_back(root->val);
        noSiblings(root->left,ans);
        noSiblings(root->right,ans);
    }
    public:
    //Node *root = new Node();
    void Solve(Node *root){
        vector<int> ans;
        noSiblings(root,ans);
        cout<<endl;
        cout<<"Hello maji radha";
        for (auto it:ans)
        { cout<<it<<" ";
        }
    }
};
int main(){
    Node *n1= new Node(37);
    Node *n2 = new Node(20);
    Node *n3 = new Node(113);
    n1->left = n2;
    n2->left = n3;
    BST obj;
    obj.Solve(n1);
    // cout<<n1->val;
}
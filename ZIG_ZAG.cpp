#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int val;
  Node *left;
  Node *right;
  Node(){
    val = 0;
    left = NULL;
    right = NULL;
  }
   Node(int data){
    val = data;
    left = NULL;
    right = NULL;
  }
};
class BST{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {  vector<int> res;
       queue<Node*> q;
       bool leftrotate = true;
       q.push(root);
       while(!q.empty()){
           int n = q.size();
           vector<int> ans(n);
           for(int i=0 ;i<n ;i++){
              int ind = leftrotate?i:n-i-1;
              auto temp = q.front();
              q.pop();
              ans[ind] = temp->val;
              if(temp->left) q.push(temp->left);
              if(temp->right)  q.push(temp->right);
           }
           for(auto it:ans) res.push_back(it);
           leftrotate = !leftrotate;
       }
       for(auto it:res) cout<<it<<" ";
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
    obj.zigZagTraversal(n1);
}
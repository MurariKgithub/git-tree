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
    void create_node(int data){
        if(isTree_empty()){
           node *new_node = new node(data);
           root = new_node;
            //cout<<"Root is inserted: "<<endl;
        }
        else{
            node *temp = new node();
            temp = root;
            node *new_node = new node(data);
            while(temp){
                if(temp->val == data){
                    //cout<<"No duplicate data is allowed\n";
                    return;
                }
                else if(temp->val>data && temp->left==NULL){
                    temp->left = new_node;
                    //cout<<"Element is inserted as the left child of "<<temp->val<<endl;
                    break;
                }
                else if(temp->val<data && temp->right==NULL){
                    temp->right = new_node;
                    //cout<<"Element is inserted as the right child of "<<temp->val<<endl;
                    break;
                }
                else if(temp->val<data){
                    temp = temp->right;
                }
                else{
                    temp = temp->left;
                }
            }
        }
    }
    void preorder(node *temp){
         if(temp == NULL) return;
        //  if(temp->left ==NULL and temp->right==NULL){
        //     cout<<"Left node -> "<<temp->val<<endl;
        //  }
        //  else{
        //  cout<<"Medial node: "<<temp->val<<endl;
        //  }
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

int main(){
    BST obj;
   
    obj.create_node(10);
    obj.create_node(7);
    obj.create_node(5);
    obj.create_node(8);
    obj.create_node(20);
    obj.create_node(13);
    // obj.create_node(14);
    // obj.create_node(19);
    cout<<"\nPre order traversal "<<endl;
    obj.preorder(obj.root);
    cout<<"\nInorder Treaversal "<<endl;
    obj.inorder(obj.root);
    cout<<"\nPost Order Traversal "<<endl;
    obj.postorder(obj.root);
    }
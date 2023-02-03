/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
  queue<TreeNode*> que;
  TreeNode *head,*nextptr;
public:
    CBTInserter(TreeNode* root) {
        head = root;
        que.push(root);
        while(true){
            auto negi = que.front();
            if(negi->left!=NULL) que.push(negi->left);
            else break;
            if(negi->right!=NULL) que.push(negi->right);
            else break;
            que.pop();
        }
        nextptr = que.front();
    }
    
    int insert(int val) {
        int data = nextptr->val;
        TreeNode *newnode = new TreeNode(val);
        que.push(newnode);
        
        if(nextptr->left==NULL)
            nextptr->left=newnode;
        
        else{
            nextptr->right=newnode;
            // change the next pointer 
            que.pop();
            nextptr = que.front();
        }
        return data;
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */

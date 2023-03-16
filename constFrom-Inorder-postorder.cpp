class Solution {
public:
    TreeNode* func(vector<int>& inorder,vector<int>& postorder,int l,int h){
        if(l>h)  return NULL;
        
        map<int,int> mp;
        for(int i=l ;i<=h ;i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root;
        int val=0,n=postorder.size();
        for(int i=n-1 ;i>=0 ;i--){
            if(mp.find(postorder[i])!=mp.end()){
                val = postorder[i];
                
                break;
            }
        }
        root = new TreeNode(val);
        root->left = func(inorder,postorder,l,mp[val]-1);
        root->right = func(inorder,postorder,mp[val]+1,h);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return func(inorder,postorder,0,postorder.size()-1);
    }
};

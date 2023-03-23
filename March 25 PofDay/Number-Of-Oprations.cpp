//Brut Force of O(n*n) solution
class Solution {
private:
   void dfs(int node,vector<vector<int>> &adjls,vector<int>& pathvis,vector<int>& vis){
        if(vis[node]) return ;
        vis[node] =1;
        pathvis[node] =1;
        for(auto it:adjls[node]){
            dfs(it,adjls,pathvis,vis);
        }
        return;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0);
        vector<vector<int>> adjls(n);
        vector<int> indeg(n,0);
        for(int i=0;i<connections.size() ;i++){
            indeg[connections[i][0]]++;
            // cout<<connections[i][0]<<endl;
            adjls[connections[i][0]].push_back(connections[i][1]);
            adjls[connections[i][1]].push_back(connections[i][0]);
        }
        int ans=0,nnode=0;
        for(int i=0 ;i<n ;i++){
            vector<int> pathvis(n,0);
            if(!vis[i]){
                dfs(i,adjls,pathvis,vis);
                int node=0,conn=0;
                for(int i=0;i<n ;i++){
                    if(pathvis[i]){
                        node++;
                        conn+=indeg[i];
                    } 
                }
                ans+=(conn-node+1);
                nnode++;
            }
        }
        // cout<<nnode<<" "<<ans<<endl;
        if(nnode==1) return 0;
        if(nnode-1>ans) return -1;
        return nnode-1;
        
    }
};
// Efficient Approch 
// T.C = O(N),S.C = O(N)
class Solution {
private:
   void dfs(int node,vector<vector<int>> &adjls,vector<int>& vis){
        if(vis[node]) return ;
        vis[node] =1;
       
        for(auto it:adjls[node]){
            dfs(it,adjls,vis);
        }
        return;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        
        vector<int> vis(n,0);
        vector<vector<int>> adjls(n);
        
        for(int i=0;i<connections.size() ;i++){
            adjls[connections[i][0]].push_back(connections[i][1]);
            adjls[connections[i][1]].push_back(connections[i][0]);
        }
        int ans=0,nnode=0;
        for(int i=0 ;i<n ;i++){
            if(!vis[i]){
                dfs(i,adjls,vis);
                nnode++;
            }
        }
        
       
        return nnode-1;
        
    }
};

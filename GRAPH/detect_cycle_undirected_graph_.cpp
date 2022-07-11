// qustion link-> https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
  public:
    // Function to detect cycle in an undirected graph.

    bool dfs_check(int src,int parent,vector<int> adj[],vector<int> vis){
        vis[src] = 1;
        for(auto i: adj[src]){
            if(!vis[i]){
                bool ans = dfs_check(i,src,adj,vis);
                if(ans) return true;
            }
            else if(i != parent) return 1;
        }
        return 0;
    }

    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visit(V,0);
        for(int i=0; i<V; i++){
            if(!visit[i]){
                bool ans = dfs_check(i,-1,adj,visit);
                if(ans) return true;
            }
        }
        return false;
    }
};

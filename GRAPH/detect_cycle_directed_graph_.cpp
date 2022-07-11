// qustion link -> https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool check(int src,vector<int> &vis,vector<int> &ord,vector<int> adj[]){
        vis[src] = 1;
        ord[src] = 1;

        for(auto i:adj[src]){
            if(!vis[i]){
                bool ans = check(i,vis,ord,adj);
                if(ans == true){
                    return true;
                }
            }
            else if(ord[i] == 1){
                return true;
            }
        }
        ord[src] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]){
        // code here
        vector<int> visit(V,0);
        vector<int> my_ord(V,0);
        for(int i=0; i<V; i++){
            if(!visit[i]){
                bool ans = check(i,visit,my_ord,adj);
                if(ans == true){
                    return true;
                }
            }
        }
        return false;
    }
};

# solution

so here we can use dfs or bfs, both solutions we will be doing

so in this code, they gave only the edges, so what we did is first we converted the edges to the adjasency matrix, and then we solved it

```cpp
class Solution {
  private:
    bool detect(int src, vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1;

        queue<pair<int,int>> q;
        q.push({src, -1});

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if(it != parent) {
                    return true;
                }
            }
        }

        return false;
    }

  public:
    bool isCycle(int V, vector<vector<int>>& edges) {

        // STEP 1: build adjacency list
        vector<vector<int>> adj(V);

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // STEP 2: visited array
        vector<int> vis(V, 0);

        // STEP 3: check all components
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true;
            }
        }

        return false;
    }
};
```
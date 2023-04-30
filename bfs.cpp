#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(int V, vector<int> adj[])
{
    vector<int> bfs_traversal;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; ++i) {
 
        // To check if already visited
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = true;                  // marking true 
            
 
            // BFS starting from ith node
            while (!q.empty()) {
                int g_node = q.front();
                q.pop();
                bfs_traversal.push_back(g_node);
                for (auto it : adj[g_node]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
    }
    return bfs_traversal;
}
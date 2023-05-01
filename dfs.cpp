#include<bits/stdc++.h>
using namespace std;


void dfs(int node , vector<int>adj[], int vis[], vector<int>&ls ){
    vis[node]=1;
    ls.push_back(node);
    //traversing all its neighbours
    for (auto it : adj[node]){
        if(vis[it]!=1){
            dfs(it , adj , vis , ls);
        }

    }
}

#include<bits/stdc++.h>

using namespace std;


void bfs(vector<vector<int>>&adj,int *parent,int src,int dest,bool *vis){
    vis[src]=1;
    parent[src]=-1;

    queue<int>q;

    q.push(src);

    while(!q.empty()){

        int front=q.front();
        q.pop();

        for(auto it:adj[front]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
                parent[it]=front;
            }
        }
    }

    int current=dest;
    vector<int>path;
    path.push_back(dest);
    while(current!=src){
        current=parent[current];
        path.push_back(current);

    }

    sort(path.begin(),path.end());

    for(auto it:path){
        cout<<it<<" ";
    }


}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
 
    int parent[n];
    bool vis[n]={0};

    int src,dest;

    cin>>src>>dest;

    bfs(adj,parent,src,dest,vis);
    
}

#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>adj,vector<bool>&vis,queue<int>&q,int node){
    vis[node]=true;

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(adj,vis,q,it);
        }
    }

    q.push(node);
}

void dfs2(vector<vector<int>>adj,vector<bool>&vis,int node){
    vis[node]=true;

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs2(adj,vis,it);
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);

    for(int i=0;i<m;i++){
        int u,v;

        cin>>u>>v;

        adj[u].push_back(v);
    }

    vector<bool>vis(n,false);
    queue<int>q;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(adj,vis,q,i);
        }
    }

    // while(!q.empty()){
    //     cout<<q.front()<<endl;
    //     q.pop();
    // }

    for(int i=1;i<=n;i++)vis[i]=false;

    int count=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        if(!vis[node]){
            count++;
            dfs2(adj,vis,node);
        }
    }

    cout<<"No of strongly connected components : "<<count<<endl;

    
    
}
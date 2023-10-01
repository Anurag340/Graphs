#include<bits/stdc++.h>

using namespace std;

bool bellmanford(vector<vector<pair<int,int>>>adj,vector<int>&dis,int src,int n,int m){
    dis[src]=0;

    //n-1 checks

    for(int i=1;i<n;i++){
        for(int u=0;u<adj.size();u++){
            for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;

            if(dis[u]!=INT_MAX && dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
            }

            }
            
        }
    }

    //for checking -ve cycle

    bool flag=false;

    for(int u=0;u<adj.size();u++){
            for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;

            if(dis[u]!=INT_MAX && dis[u]+w<dis[v]){
                flag=true;
                dis[v]=dis[u]+w;
            }

            }
            
        }
    if(flag)return 0;
}


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>>adj(n);

    for(int i=0;i<m;i++){
        int u,v,w;

        cin>>u>>v>>w;

        adj[u].push_back({v,w});
    }

    vector<int>dis(n,INT_MAX);

    bool ans=bellmanford(adj,dis,0,n,m);

    if(ans)cout<<" -ve cycle "<<endl;
    else{
        for(auto it:dis){
        cout<<it<<" ";
    }
    cout<<endl;
    }

    
}
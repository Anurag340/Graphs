#include<bits/stdc++.h>

using namespace std;

void topo(int node ,stack<int>&s,vector<vector<pair<int,int>>>&adj,vector<bool>&vis){
    
    vis[node]=true;


    for(auto it:adj[node]){
        if(!vis[it.first]){
            topo(it.first,s,adj,vis);
        }
    }

    s.push(node);
}

void shortestpath(int src,stack<int>&s,vector<vector<pair<int,int>>>&adj,vector<int>&dis){
    dis[src]=0;

    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(dis[top]!=INT_MAX){
            for(auto it:adj[top]){
                if(dis[top]+it.second<=dis[it.first]){
                    dis[it.first]=dis[top]+it.second;
                }

            }

        }
        
    }

}

int main(){
    int n,m;

    cin>>n>>m;

    vector<vector<pair<int,int>>>adj(n);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        pair<int,int>p={v,w};
        adj[u].push_back(p);
    }

    for(auto it:adj){
        for(auto i :it){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }

    stack<int>s;

    vector<bool>vis(n,false);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            topo(i,s,adj,vis);

        }
    }

    vector<int>dis(n);
    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;
    }

    shortestpath(0,s,adj,dis);

    for(auto it:dis){
        cout<<it<<" ";
    }
    cout<<endl;
}
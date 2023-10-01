#include<bits/stdc++.h>

using namespace std;

void dijkstra(vector<vector<pair<int,int>>>adj,vector<int>&dis,int src){

    dis[src]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({src,0});

    while(!pq.empty()){
        pair<int,int>x=pq.top();
        int dist=x.second;
        int node=x.first;

        pq.pop();

        for(auto it:adj[node]){
            if(dist+it.second<dis[it.first]){
                dis[it.first]=dist+it.second;
                pq.push({it.first,dis[it.first]});
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

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int>dis(n);
    for(int i=0;i<n;i++)dis[i]=1e9;

    dijkstra(adj,dis,0);

    for(auto it:dis){
        cout<<it<<" ";
    }
    cout<<endl;
}
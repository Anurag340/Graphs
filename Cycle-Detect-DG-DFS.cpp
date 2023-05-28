#include<bits/stdc++.h>
using namespace std;

bool iscycledfs(int node , unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis,unordered_map<int,bool>dfsvis){
    dfsvis[node]=true;
    vis[node]=true;

    for(auto it: adj[node]){
        if(!vis[it]){
            bool cycle = iscycledfs(it,adj,vis,dfsvis);
            if(cycle){
                return true;
            }
        }
        else if(vis[it] && dfsvis[it]){
            return true;
        }

    }
    dfsvis[node]=false;
    return false; 

}

bool connected_Components(int n, unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj){
    unordered_map<int,bool>dfsvis;
    for(int i=0;i<n;i++){
    if(!vis[i]){
        bool ans=iscycledfs(i,adj,vis,dfsvis);
        if(ans){
            cout<<"Yes"<<endl;
        }

    }


 }
 cout<<"No"<<endl;

}


int main(){
 int n;

 
 cout<<"Enter the number of nodes:"<<endl;
 cin>>n;
 unordered_map<int,bool>vis;
 int e;
 cout<<"Enter the number of edges:"<<endl;
 cin>>e;
 unordered_map<int,list<int>>adj;
 cout<<"Enter the edges:"<<endl;
 for(int i=0 ; i<e ; i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);

 }

 bool ans= connected_Components(n,vis,adj);

 cout<<ans<<endl;



}
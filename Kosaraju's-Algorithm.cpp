#include<bits/stdc++.h>
using namespace std;

void toposort_dfs(int node ,int parent,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj,stack<int>&s){
    vis[node]=true;
    for(auto it:adj[node]){
        if(!vis[it]){
            toposort_dfs(it,node,vis,adj,s);


        }

    }
    s.push(node);
}


void connected_components(int node,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj,stack<int>&s){
    for(int i=0;i<node;i++){
        if(!vis[i]){
            toposort_dfs(i,-1,vis,adj,s);
        }
    }
}



void reverse_dfs(int node ,int parent,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj){
    vis[node]=true;
    for(auto it:adj[node]){
        if(!vis[it]){
            reverse_dfs(it,node,vis,adj);


        }

    }
}

int main(){
    int n , e;
    unordered_map<int,list<int>>adj;
    unordered_map<int,bool>vis;
    stack<int>s;
    cout<<"Enter the number of nodes:"<<endl;
    cin>>n;
    cout<<"Enter the number of edges:"<<endl;
    cin>>e;
    cout<<"Enter the edges:"<<endl;

    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);  // Since it is a DAG , we are going to push the node once .


    }
    connected_components(n,vis,adj,s);

    // Reversing the adjacency list or transposing it .

    unordered_map<int,list<int>>transpose;

    for(int i=0 ; i<n ; i++){

        vis[i]=0;                    //Note this , here we have to reset the visited .

        for(auto it : adj[i]){
            transpose[it].push_back(i);

        }

    }

    int count=0;

    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            reverse_dfs(i,-1,vis,transpose);
            count++;
        }
    }

    cout<<count<<endl;


}

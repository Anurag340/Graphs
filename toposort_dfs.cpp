/* In this program we are going to implement topological sorting using DFS.

   1)We are going to use the DFS.

   2)Rather than printing the nodes directly after the recursive call we are

   going to store the nodes in the stack and print the content of the stack afterwards.

   3) Note that this can only be applied on DAG(Directed acyclic graph)

      */

#include<bits/stdc++.h>
using namespace std;

bool toposort_dfs(int node ,int parent,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj,stack<int>&s){
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

    // To display the content of the stack , it is what did our sorting .

    for(int i=0;i<s.size();i++){
        int ans = s.top();
        cout<<ans<<" ";
        s.pop();
    } 



}

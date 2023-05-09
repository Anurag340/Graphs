/*In this program we are going to detect cycle using DFS , and since its DFS recursion is going to be used.

  1) Data Structures used are ajacency list and a visited array  , unlike BFS we dont need to create mapping for parent 
  as we can just alter the values for parent during the recursion call .
  
  2) So pass the parent as integer type only .
  
  3) The condition will remain same for cycle detection i.e. the child should be visited and it should not be equal to it's parent .   */



#include<bits/stdc++.h>
using namespace std;

bool iscycledfs(int node ,int parent, unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis){
    vis[node]=true;

    for(auto it: adj[node]){
        if(!vis[it]){
            bool cycle = iscycledfs(it,node,adj,vis);
            if(cycle){
                return true;
            }
        }
        else if(vis[it] && it!=parent){
            return true;
        }

    }
    return false; 

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
 for(int i=0;i<n;i++){
    if(!vis[i]){
        bool ans=iscycledfs(i,-1,adj,vis);
        if(ans){
            cout<<"Yes"<<endl;
        }

    }


 }
 cout<<"No"<<endl;




}
/* In this program we are going to detect cycle  using BFS traversal

   1) Data structures involved are visited array , adjacency list, parent mapping with all as unorderd_map types .

   2) Condition to detect cycle is --> the child should be marked as visited and it should not be equal to its parent . 

   3) Hence it proves to contain a cycle and the rest code will remain same as BFS for unmarked child --> just push it into the queue
      mark it as visited , map it to its parent and there yo go .
*/


#include<bits/stdc++.h>
using namespace std;


bool iscyclebfs(int node , unordered_map<int,list<int>>&adj,unordered_map<int,bool>&vis){


unordered_map<int,int>parent;        // To store the respective node with its parents 
vis[node]=true;
parent[node]=-1;

queue<int>q;
q.push(node);

while(!q.empty()){
    int front= q.front();
    q.pop();


    for(auto it:adj[front]){
        if(vis[it]==true && it!=parent[front]){             // Condition for the detection of cycle
            return true;
        }
        else if(!vis[it]){
            q.push(it);
            vis[it]=true;
            parent[it]=front;
        }

    }
    return false;
}
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
        bool ans=iscyclebfs(i,adj,vis);
        if(ans){
            cout<<"Yes"<<endl;
        }

    }


 }
 cout<<"No"<<endl;




}
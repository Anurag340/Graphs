#include<bits/stdc++.h>
using namespace std;

void topo_bfs(int node ,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj,queue<int>&q,int v){
    vector<int>indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

// Push all the nodes that have 0 indegree

    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    // Perform bfs
    vector<int>ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto it:adj[front]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }


    }

    // Printing the sorted answer

    for(auto it:ans){
        cout<<it<<" ";
    }

}

int main(){
    int n , e;
    unordered_map<int,list<int>>adj;
    unordered_map<int,bool>vis;
    queue<int>q;
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
    topo_bfs(n,vis,adj,q,e);
}
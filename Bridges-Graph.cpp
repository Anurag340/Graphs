#include<bits/stdc++.h>
using namespace std;

int bridges(int node , int parent , int timer ,vector<vector<int>>&result,unordered_map<int,bool>&vis,vector<int>&disc,
vector<int>&low,unordered_map<int,list<int>>&adj
){
    vis[node]=true;
    low[node]=disc[node]=timer++;


    for(auto it: adj[node]){
        if(it == parent){
            continue;
        }
        if(!vis[it]){
            bridges(it,node,timer,result,vis,disc,low,adj);
            low[node]=min(low[node],low[it]);


            //Conditon for the bridge to detect
            if(low[it]>disc[node]){
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(it);
                result.push_back(ans);

            }
        }

        //Back edge case
        else if(vis[it] && it!=parent){
            low[node]=min(low[node],disc[it]);
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
int timer=0;
vector<int>disc;
vector<int>low;
vector<vector<int>>result;


 for(int i=0;i<n;i++){
    if(!vis[i]){
        bridges(i,-1,0,result,vis,disc,low,adj);
        
    }


 }
 for(auto i : result){
    for(auto j : i){
        cout<<j<<" ";
    }
 }




}
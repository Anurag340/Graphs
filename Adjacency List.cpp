#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int u,v;
    vector<vector<int>>ve(n);
    for(int i=0;i<m;i++){
        
        cin>>u>>v;

        ve[u].push_back(v);
        ve[v].push_back(u);


    }

   for(auto i:ve){
    for(auto j:i){
        cout<<j<<" ";
    }
    cout<<endl;
   }
 }

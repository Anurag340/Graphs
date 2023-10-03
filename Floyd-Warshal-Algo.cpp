#include<bits/stdc++.h>

using namespace std;

void floydwarshal(int mat[3][3],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==-1)mat[i][j]=1e9;
        }
    }

    //floyd warshal algo

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);

            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1e9)mat[i][j]=-1;
        }
    }


}

int main(){
    int n,m;
    cin>>n>>m;
    int mat[3][3]={{0,1,43},{1,0,6},{-1,-1,0}};

    floydwarshal(mat,3);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
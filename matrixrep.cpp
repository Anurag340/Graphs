#include <iostream>
using namespace std;

int main(){
    int v,e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    int u,l,mat[10][10] = {0};
    for(int i=0;i<e;i++){
        cin >> u >> l;
        mat[u][l] = 1;
        mat[l][u] = 1;
    }
    cout << "Do you want to print the graph? (yes or no) ";
    string ch;
    cin >> ch;
    if(ch=="yes"){
        cout << "Adjacency matrix:\n";
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else{
        return 0;
    }
    return 0;
}
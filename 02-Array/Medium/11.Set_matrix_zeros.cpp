#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void matrixRow(vector<vector<int>>& matrix, int i){
    int n=matrix.size();
    int m=matrix[0].size();

    for(int j=0; j<m; j++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}
void matrixCol(vector<vector<int>>& matrix, int j){
    int n=matrix.size();
    int m=matrix[0].size();

    for(int i=0; i<n; i++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}

// Bruteforce
void Bruteee(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                matrixRow(matrix, i);
                matrixCol(matrix, j);
            }
        }
    }
    // put back -1 as zeros
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }

}

// Better
void Better(vector<vector<int>>& arr){
    int n=arr.size();
    int m=arr[0].size();

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    // first pass -> if zero is there mark row[i] and col[j] = 1 repectively
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // pass 2 -> if any moment row and col arr is marked put entire col and row as 0
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i] == 1 || col[j] == 1){
                arr[i][j] = 0;
            }
        }
    }
}

//optimal
void Optimal(vector<vector<int>>& arr){
    int n= arr.size();
    int m= arr[0].size();

    // int row[n] => arr[i][0]
    // int col[m] => arr[0][j]

    int col0=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0) {
                // mark i-th row
                arr[i][0]=0;
                
                // mark j-th col
                if(j != 0)
                    arr[0][j] = 0;
                else
                    col0= 0;
            }
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][j] != 0){
                if(arr[0][j]==0 || arr[i][0]==0){
                    arr[i][j]=0;
                }
            }
        }
    }

    if(arr[0][0] == 0){
        for(int j=0; j<m; j++){
            arr[0][j]=0;
        }
    }
    if(col0 == 0){
        for(int i=0; i<n; i++){
            arr[i][0] = 0;
        }
    }

}
int main(){

    int n; cin>>n;
    int m; cin>>m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }

    Optimal(matrix);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

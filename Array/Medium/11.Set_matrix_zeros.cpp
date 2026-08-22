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
void setZeroes(vector<vector<int>>& matrix) {
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

int main(){

    int n; cin>>n;
    int m; cin>>m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }

    setZeroes(matrix);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

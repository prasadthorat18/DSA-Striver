#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brutee(int n,int f, vector<int>& arr){

    int len=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum=0;
            for(int k=i; k<j; k++){
                sum += arr[k];
            }
            if(sum==f){
                len=max(len, j-i+1);
            } 
        }
    }
}

int main(){
    int n;
    cin>>n;

    int f;
    cin>>f;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}
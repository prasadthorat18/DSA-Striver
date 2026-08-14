#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brutee(int n, vector<int>& arr){

    int profit=0;
    int maxi= 0;
    for(int i=0; i<n; i++){

        for(int j=i+1; j<n; j++){
            profit = arr[j]-arr[i];

            maxi= max(profit, maxi);
        }
    }
    return maxi;
}

int optimal(int n, vector<int>& arr){
    
    int profit=0;
    int maxi=0;
    int mini=arr[0];

    for(int i=1; i<n; i++){

        profit = arr[i] - mini;
        
        maxi= max(maxi, profit);

        mini= min(mini, arr[i]);
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<brutee(n, arr)<<endl;
    cout<<optimal(n, arr);
}
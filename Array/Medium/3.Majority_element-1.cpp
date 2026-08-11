#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brutee(int n, vector<int>& arr){

    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(arr[i] == arr[j]) cnt++;
        }
        if(cnt> n/2) return arr[i];
    }
    return -1;

}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<brutee(n, arr);

    

    return 0;
}
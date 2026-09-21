#include<bits/stdc++.h>
using namespace std;

int hash2[10000000];  // max 10^7 globally

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //precompute
    int hash[13]={0};
    for(int i=0; i<n; i++){
        hash[arr[i]] += 1;
    }


    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;
    }

    int hash1[1000000];  //10^6 is max inside main

    return 0;
}
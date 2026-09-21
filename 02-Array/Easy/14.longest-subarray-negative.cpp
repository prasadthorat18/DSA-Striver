#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brutee(int n,int f, vector<int>& arr){

    int len=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum=0;
            for(int k=i; k<=j; k++){
                sum += arr[k];
            }
            if(sum==f){
                len=max(len, j-i+1);
            } 
        }
    }
    return len;
}

int brutee2(int n,int f, vector<int>& arr){

    int len=0;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum += arr[j];

            if(sum==f){
                len=max(len, j-i+1);
            }
        }
    }
}

int Optmial_for_postive_negative_zeros(int n,int key, vector<int>& arr){
    map<long long, int> mp;
    long long sum=0;
    int maxLen=0;

    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum == key){
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum -key;
        if(mp.find(rem) != mp.end()){
            int len = i - mp[rem];
            maxLen = max(maxLen, len);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum]=i;
        }
    }
    return maxLen;

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
    cout<<Optmial_for_postive_negative_zeros(n,f,arr);
}
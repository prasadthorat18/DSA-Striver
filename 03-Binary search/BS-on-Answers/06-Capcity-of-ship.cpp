#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool DaysReq(vector<int>& weights,int capacity, int days){

    int day = 1;
    int load = 0;
    for(int i=0; i<weights.size(); i++){

        if( (load + weights[i]) > capacity ){
            day = day + 1;
            load = weights[i];
        }
        else{
            load = load + weights[i];
        }
    }
    if(day <= days) return true;
        else return false;
}

//Brutee -> T.c -> O[N * (summation - maxi + 1)]

int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    
    int maxi = *max_element(weights.begin(), weights.end());

    long long sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + weights[i];
    }

    for(int i=maxi; i<=sum; i++){
        if(DaysReq(weights, i, days)) return i;
    }
    return -1;
}

//Optimal- BS -> T.c -> O[N * log(summation - maxi + 1)]
int shipWithinDays_BS(vector<int>& weights, int days) {
    int n = weights.size();
    
    int maxi = *max_element(weights.begin(), weights.end());

    long long sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + weights[i];
    }

    int low = maxi;
    int high = sum;
    while( low <= high){
        int mid = low +(high - low) / 2;

        if(DaysReq(weights, mid, days)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low; 
}

int main(){
    int n;
    cin>>n;

    vector<int> bloomDay(n);
    for(int i=0; i<n; i++){
        cin>>bloomDay[i];
    }
    int m; cin>>m;
    int k; cin>>k;

    // cout<<minDays_BS(bloomDay,m, k);
}
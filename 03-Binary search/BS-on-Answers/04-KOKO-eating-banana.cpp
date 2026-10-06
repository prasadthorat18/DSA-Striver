#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long Kth_speed(int k,vector<int>& piles ){
        
    long long sum = 0;
    for(int i=0; i< piles.size(); i++){
        sum = sum + ceil( (double)(piles[i]) / (double)(k) );
    }
    return sum;
}

int minEatingSpeed(int n, vector<int>& piles, int h) {


    long long maxi = *max_element(piles.begin(), piles.end());

    for(long long k = 1; k <= maxi; k++){

        if(Kth_speed(k, piles) <= h ) return k;
    }

    return -1;
}

//Optimal using -> Binary search offcourse

int Time_hours(int mid, vector<int>& piles, int h){
    long long hrs =0;
    for(int i=0; i<piles.size(); i++){
        hrs = hrs + ceil( (double)piles[i] / (double)mid );
        if( hrs > h){
            return hrs;  // to save our time too
        }
    }
    return hrs;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();

    int maxi = *max_element(piles.begin(), piles.end());

    int low = 1;
    int high = maxi;

    while( low <= high){
        
        int mid = (low + high ) / 2;

        long long TimeReq = Time_hours(mid, piles,h);

        if( TimeReq <= h ){
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

    vector<int> piles(n);
    for(int i=0; i<n; i++){
        cin>> piles[i];
    }
    int h;
    cin>>h;

    cout<<minEatingSpeed(n, piles, h);
}
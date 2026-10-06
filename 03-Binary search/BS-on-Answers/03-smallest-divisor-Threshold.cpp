#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int divisor(int d, vector<int> &arr, int n, int limit){

    
    int sum =0;
    for(int i=0; i<n; i++){
        sum = sum + ceil( (double)(arr[i]) / (double)(d) ); // to found out ceil...
    }
    return sum;
}

int smallestDivisor(vector<int> &arr, int n, int threshold) {


    int MaxValue = *max_element(arr.begin(), arr.end());

    for(int d = 1; d <= MaxValue; d++){

        int ans = 0;
        if(divisor(d, arr, n, threshold) <= threshold) return d;

    }
    return -1;
}
int divisor_BS(int mid, vector<int> &arr, int n, int threshold){

    
    int sum =0;
    for(int i=0; i<n; i++){
        sum = sum + ceil( (double)(arr[i]) / (double)(mid) ); // to found out ceil...
    }
    return sum;
}

int smallestDivisor_BS(vector<int> &arr, int n, int threshold){

    int maxi = *max_element(arr.begin(), arr.end());

    int low = 1;
    int high = maxi;
    
    int ans = 0;

    while( low <= high){
        int mid = (low + high) / 2;

        
        if(divisor_BS(mid, arr, n, threshold) <= threshold){
            ans = mid ;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int threshold;
    cin>>threshold;
}
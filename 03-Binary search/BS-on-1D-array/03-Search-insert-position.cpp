#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Search_insert_position(vector<int>&arr, int n, int target){
 
    for(int i=0; i<n; i++){
        if(arr[i] >= target){
            return i;
        }
    }
    return n;

}

// use lower bound here gives exact same answer

int Search_insert_position_BS(vector<int>& arr, int n, int target){

    int low=0;
    int high = n-1;
    int ans = n;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == target) return mid;

        else if(arr[mid] > target){
            ans = mid;
            high = mid -1 ;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int Search_insert_position_lb(vector<int>& arr, int n, int target){
    int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        
    return lb;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;

    cout<<Search_insert_position(arr,n,target)<<endl;

    cout<<Search_insert_position_BS(arr,n,target)<<endl;

    cout<<Search_insert_position_lb(arr,n,target);
}
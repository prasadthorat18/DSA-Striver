#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brutee_LS(int n, vector<int>& arr, int target){

    int cnt=0;
    for(int i=0; i<n; i++){
        if(arr[i] == target) cnt++;
    }
    return cnt;
}

int lb_ub__BS(int n, vector<int>& arr, int target){

    int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

    if(lb == n || arr[lb] != target) return 0; 

    int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

    return ub-lb;
}

int Optimal_BS(int n, vector<int>& arr, int target){
     int first = firstoccurnace(n,arr,target);
     if(first == -1) return 0;

     int last = lastoccurnace(n,arr,target);
     return (last-first)+1;

}
int firstoccurnace(int n, vector<int>& arr, int target){

    int first = -1;
    int low=0; int high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == target){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < target){
            low = mid +1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}
int lastoccurnace(int n, vector<int>& arr, int target){

    int last = -1;
    int low=0; int high = n-1;
    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == target){
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return last;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int target;
    cin>> target;
}
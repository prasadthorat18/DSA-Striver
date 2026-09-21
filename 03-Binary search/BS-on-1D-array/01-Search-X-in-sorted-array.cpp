#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Search_X_Iterative(vector<int>&arr, int n, int target){

    int low=0;
    int high= n-1;

    while(low <= high){
        int mid= ( low + high ) / 2;

        if(arr[mid] == target) return mid;

        else if(arr[mid] > target){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;

}

int Search_x_Recursive(vector<int>&arr, int low, int high, int target){

    if(low > high ) return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target) return mid;

    else if(target > arr[mid]){
        return Search_x_Recursive(arr, mid+1, high, target);
    }
    else{
        return Search_x_Recursive(arr, low, mid-1, target);
    }
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

    // cout<<Search_X_Iterative(arr,n,target);

    cout<<Search_x_Recursive(arr, 0, n-1, target);

}
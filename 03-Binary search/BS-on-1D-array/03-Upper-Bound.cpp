#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Upper_bound(vector<int>&arr, int n, int x){

    int low=0;
    int high= n-1;
    int ans = n;

    while(low <= high){
        int mid= ( low + high ) / 2;

        if(arr[mid] > x){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;

}

int Upper_bound_CPP_Shorthand(vector<int>& arr, int n, int x){

    int ub= upper_bound(arr.begin(), arr.end(), x) - arr.begin();

    return ub;
}


int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;

    cout<<Upper_bound_CPP_Shorthand(arr,n,x)<<endl;

    cout<<Upper_bound(arr,n,x);
}
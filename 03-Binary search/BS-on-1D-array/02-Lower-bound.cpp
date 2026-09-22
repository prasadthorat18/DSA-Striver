#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Lower_bound(vector<int>&arr, int n, int x){

    int low=0;
    int high= n-1;
    int ans = n;

    while(low <= high){
        int mid= ( low + high ) / 2;

        if(arr[mid] >= x){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;

}

int Lower_bound_CPP_Shorthand(vector<int>& arr, int n, int x){

    int lb= lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    return lb;
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

    cout<<Lower_bound_CPP_Shorthand(arr,n,x)<<endl;

    cout<<Lower_bound(arr,n,x);
}
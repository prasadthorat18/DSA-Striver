#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> getFloorAndCeil(vector<int> arr, int x) {

    int n = arr.size();
    int low=0;
    int high = n-1;

    int Floor_ans=-1;
    int Ceil_ans= -1;

    
    while(low <= high){
        int mid = (low + high ) / 2;

        if(arr[mid] == x){
            return {x,x};
        }

        if(arr[mid] < x){
            Floor_ans = arr[mid];
            low = mid + 1;
        }
        else {
            Ceil_ans = arr[mid];
            high = mid - 1;
        }
    }

    return {Floor_ans, Ceil_ans};

}



vector<int> getFloorAndCeil_2(vector<int> arr, int x) {

    int n = arr.size();
    int low=0;
    int high = n-1;

    int Floor_ans=-1;
    int Ceil_ans=-1;

    
    while(low <= high){
        int mid = (low + high ) / 2;

        if(arr[mid] <= x){
            Floor_ans = arr[mid];
            low = mid + 1;
        }
        else {
            high = high - 1;
        }
    }

    int lb= lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    if(lb < n){
        Ceil_ans = arr[lb];
    }

    return {Floor_ans, Ceil_ans};

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

    vector<int> result = getFloorAndCeil_2(arr,x);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    vector<int> result2 = getFloorAndCeil(arr,x);
    for(int i=0; i<result2.size(); i++){
        cout<<result2[i]<<" ";
    }


}
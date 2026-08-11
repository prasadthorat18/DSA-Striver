#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> brutee(int n, vector<int>& arr){

    sort(arr.begin(), arr.end());

    return arr;
}

vector<int> better(int n, vector<int>& arr){

    int cnt0=0, cnt1=0, cnt2=0;

    for(int i=0; i<n; i++){
        if(arr[i]==0) cnt0++;
        else if(arr[i]==1) cnt1++;
        else cnt2++;
    }
    for(int i=0; i<cnt0; i++) arr[i]=0;
    for(int i=cnt0; i<cnt0+cnt1; i++) arr[i]=1;
    for(int i=cnt0+cnt1; i<n; i++) arr[i]=2;

    return arr;
}

vector<int> optimal(int n, vector<int>& arr){

    
    int low=0, mid=0, high=n-1;

    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1) mid++;

        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    return arr;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


    optimal(n,arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}
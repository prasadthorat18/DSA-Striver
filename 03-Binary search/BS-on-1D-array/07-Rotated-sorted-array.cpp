#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Brutee_LS(vector<int>& arr, int n, int x){

    for(int i=0; i<n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int Optimal_BS(vector<int>& arr,int n, int x) {
        
    int low=0;
    int high = n-1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == x){
            return mid;
        }

        if(arr[low] <= arr[mid]){
            if(arr[low] <= x && x <= arr[mid]){
                high= mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(arr[mid] <= x && x <= arr[high]){
                low= mid + 1;
            }
            else{
                high = mid - 1;
            }
        }  
    }
    return -1;
}
int main (){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;

    cout<<Brutee_LS(arr, n, x);
    cout<<Optimal_BS(arr, n, x);
}
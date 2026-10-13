#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// my approach  -> [O(n * 2000)]
bool missing(int num, vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == num) return false;
    }
    return true;
}

int findKthPositive(vector<int>& arr, int k) {

    int elem = 0;
    for(int i=1; i<=2000; i++){

        if(missing(i, arr)) elem++;

        if(elem == k) return i;
    }
    return -1;   
}

// striver bruteee -> {o(n)}

int findKthPositive_bettter(vector<int>& arr, int k) {
    int n= arr.size();
    for(int i=0; i<n; i++){

        if(arr[i] <= k) k++;
        else{
            break;
        }
    }
    return k;
}

// binary search -> prefer books and notes for it..

int findKthPositive(vector<int>& arr, int k) {
    int n= arr.size();

    int low =0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        
        int missing = arr[mid] - (mid+1);  // 7- 3+1

        if(missing < k) low = mid + 1;
        else high = mid - 1;
    }
    return low+k;
}


int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;

    cout<<findKthPositive(arr, k);
}
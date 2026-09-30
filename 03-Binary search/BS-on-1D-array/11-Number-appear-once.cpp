#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MYbrutee(int n, vector<int>& arr){

    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(arr[i] == arr[j]) cnt++;
        }
        if(cnt == 1) return arr[i];
    }
    return -1;
}

int striverBetter(int n, vector<int> &arr){

    int maxi = arr[0];
    for(int i=0; i<n; i++){
        maxi = max(arr[i], maxi);
    }

    vector<int> hash(maxi+1, 0);
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }

    for(int i=0; i<n; i++){
        if(hash[arr[i]] == 1) return arr[i];
    }

    return -1;
}

int MYbetter(int n, vector<int>& arr){

    map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    for(auto it : mp){
        if(it.second == 1) return it.first;
    }
    return -1;
}

int optimal_XOR(int n, vector<int>& arr){

    int xorr=0;
    for(int i=0; i<n; i++){
        xorr= xorr ^ arr[i];
    }
    return xorr;
}

int Most_OPTIMAL_BS(int n, vector<int>& arr){

    if(n==1) return arr[0];

    if(arr[0] != arr[1]) return arr[0];

    if(arr[n-1] != arr[n-2]) return arr[n-1];

    int low=0; int high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }

        // left side is okay (even, odd) --> element on right side
        if( (mid % 2 == 1 && arr[mid] == arr[mid-1]) || (mid % 2 == 0 && arr[mid] == arr[mid+1]) ){
            low = mid +1;
        }
        // right side of single element (odd, even) --> go on left
        else{
            high = mid - 1;
        }
    }
    return -1;
}


int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<optimal_XOR(n, arr);
}
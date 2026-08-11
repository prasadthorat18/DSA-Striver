#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int majorityElement_Brutee(int n, vector<int>& arr){

    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(arr[i] == arr[j]) cnt++;
        }
        if(cnt> n/2) return arr[i];
    }
    return -1;

}

int majorityElement_Better(int n, vector<int>& arr) {

    map<int, int> mpp;

    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second > n/2) return it.first;
    }
    return -1;
        
}

// moore's Voting Algorithm
int majorityElement_Optimal(int n, vector<int>& arr) {

    int cnt=0;
    int el;
    for(int i=0 ;i<n; i++){
        if(cnt == 0){
            el=arr[i];
            cnt=1;
        }
        else if(arr[i] == el){
            cnt++;
        }
        else{
            cnt--;
        } 
    }

    // int cnt2=0;
    // for(int i=0; i<n; i++){
    //     if(arr[i]==el) cnt2++;
    // }
    // if(cnt2 > n/2) return el;

    // return -1;

    // the question already state that majority element is always presrent so direct print el
    
    return el;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<majorityElement_Optimal(n, arr);

    

    return 0;
}
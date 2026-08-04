#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brutee(int n,int key, vector<int>& arr){

    int len=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum=0;
            for(int k=i; k<=j; k++){
                sum += arr[k];
            }
            if(sum==key){
                len=max(len, j-i+1);
            } 
        }
    }
    return len;
}

int brutee2(int n,int key, vector<int>& arr){

    int len=0;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum += arr[j];

            if(sum==key){
                len=max(len, j-i+1);
            }
        }
    }
    return len;
}


int optimal_positives_zeros(int n, int key, vector<int>& arr){

    int left=0; int right=0;
    long long sum=arr[0];
    int maxLen = 0;

    while(right < n){
        while(sum>key && right >= left){
            sum -= arr[left];
            left++;
        }
        if(sum == key ){
            maxLen=max(maxLen, right-left+1);
        }
        right++;
        if(right < n) sum += arr[right];
    }
    return maxLen;

}

int main(){
    int n;
    cin>>n;

    int key;
    cin>>key;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<optimal_positives_zeros(n,key,arr);
}
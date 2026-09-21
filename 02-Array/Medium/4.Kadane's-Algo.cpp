#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Find_max_sum_Brutee(int n, vector<int>& arr){

    long long maxi=LONG_MIN;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            long long sum=0;
            for(int k=i; k<=j; k++){
                sum=sum+arr[k];
            }
            maxi=max(sum, maxi);
        }
    }
    return maxi;

}

int Find_max_sum_Better(int n, vector<int>& arr){

    long long maxi=LONG_MIN;
    for(int i=0; i<n; i++){
        long long sum=0;
        for(int j=i; j<n; j++){
            sum=sum+arr[j];

            maxi=max(sum, maxi);
        }
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    

    

    return 0;
}
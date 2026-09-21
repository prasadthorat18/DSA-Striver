#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> brutee(int n, vector<int>& arr){
    // by using recursion we can find all possible permutations

    // there are N! pemutations are there

    //  so T.C => O(n! * n) which is not humanly possible if array is having more than 13 or 14 elements
}

vector<int> optimal(int n, vector<int>& arr){

    next_permutation(arr.begin(), arr.end());

    return arr;
}


int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    optimal(n, arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
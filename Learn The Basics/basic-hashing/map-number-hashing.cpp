#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //pre-compute
    // map<int , int> mpp;
    unordered_map<int, int>mpp;  // try this first bcoz of t.c

    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }

    // iteration in map       -------> map always stores value in sorted order
    for(auto it : mpp){ 
        cout<<it.first<<"->"<<it.second<<endl;
    }
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;

        //fetch
        cout<<mpp[number]<<endl;
    }

}
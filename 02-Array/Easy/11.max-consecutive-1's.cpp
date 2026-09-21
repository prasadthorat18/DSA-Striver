#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MYbrutee(int n, vector<int>& arr){
    int cnt=0;
    int ans=0;
    for(int i=0; i<n; i++){
       if(arr[i]==1){
        cnt++;
        ans= max(ans, cnt);
       }
       else{
        cnt=0;
       }
    }
    return ans;
}
 
int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<MYbrutee(n, arr);
}
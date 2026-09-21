#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// T.C => approx O(N^2) 
// S.C => O(1)   that's O(n) i used for delvering the ans not for solving

vector<int> brutee(int n, vector<int>& arr){

    vector<int> leader;
    for(int i=0; i<n; i++){
        bool flag = true;
        for(int j=i+1; j<n; j++){
            if(arr[i] <= arr[j]){
                flag = false;
                break;
            }
        }
        if(flag) leader.push_back(arr[i]);
    }
    return leader;
}

// T.C => approx O(N) + O(n.logn) if they says we want solution in sorted order or
        //   O(N) + O(N) for reverse the array
// S.C => O(1)   that's O(n) i used for delvering the ans not for solving
vector<int> optimal(int n, vector<int>& arr){

    vector<int> leader;
    leader.push_back(arr[n-1]);

    int maxi = arr[n-1];
    for(int i=n-2; i>=0; i--){
        if(arr[i] > maxi){
            leader.push_back(arr[i]);
        }
        maxi = max(arr[i], maxi);
    }
    return leader;
}
int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> ans=optimal(n, arr);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
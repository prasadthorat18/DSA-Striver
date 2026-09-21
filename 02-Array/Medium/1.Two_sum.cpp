#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void brutee(int n, vector<int>& arr, int target){

    bool flag=false;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i+1; j<n; j++){
            sum=arr[i]+arr[j];
            if(sum==target){
                flag=true;
                cout<<"Target is Found at :"<<i<<" "<<j;
                break;
            }
        }
    }
    if(flag==false) cout<<"target is not found"<<endl;
    
}

vector<int> optimal_for_variety2(int n, vector<int>& arr, int target){

    map<int, int>mpp;
    for(int i=0; i<n; i++){
        int current=arr[i];
        int MoreNeed = target- current;
        if(mpp.find(MoreNeed) != mpp.end()){
            return { mpp[MoreNeed], i };
        }
        mpp[current] = i ;
    }
    return {-1, -1};
}

string optimal_for_variety1(int n, vector<int>& arr, int target){

    sort(arr.begin(), arr.end());

    int left=0;
    int right=n-1;

    int sum=0;
    while(left<right){
        sum=arr[left]+arr[right];
        if(sum==target){
            return "YES";
        }
        else if(sum < target){
            left++;
        }
        else if(sum > target){
            right--;
        }
    }
    return "NO";
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int target; cin>>target;

    vector<int> ans= optimal_for_variety2(n,arr,target);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    

    return 0;
}
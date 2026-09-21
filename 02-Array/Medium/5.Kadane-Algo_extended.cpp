#include<bits/stdc++.h>
using namespace std;

vector<long long> PrintTheMax_Subarray(int n, vector<int>& arr){

    long long sum=0;
    long long maxi=0;
    int start=0;

    int startindex=0;
    int endindex=0;
    for(int i=0; i<n; i++){
        if(sum==0) start=i;
        sum += arr[i];

        if(sum>maxi){
            maxi=sum;
            startindex=start;
            endindex=i;
        }

        if(sum<0){
            sum=0;
        }
        return {maxi, startindex, endindex};
    }

}

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<long long> ans= PrintTheMax_Subarray(n, arr);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
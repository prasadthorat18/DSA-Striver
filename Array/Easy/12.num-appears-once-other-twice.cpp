#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MYbrutee(int n, vector<int>& arr){   // T.c -> O(n^2)  S.c -> O(1)
    
    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(arr[i]==arr[j]){
                cnt++;
            }
        }
        if(cnt==1) return arr[i];
    }
    return -1;
}

int striverBetter(int n, vector<int> &arr){ // T.c -> O(3n)  S.c -> O(max element)
                                            // if size is 10^9 then its gets worse so avoid it
    int ans=arr[0];
    for(int i=0; i<n; i++){
        ans=max(arr[i], ans);
    }

    int hash[ans+1]={0};
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }

    for(int i=0; i<n; i++){
        if(hash[arr[i]]==1) return arr[i];
    }

    return -1;
}

int MYbetter(int n, vector<int>& arr) {   // T.c -> O(n. logn) + O(n/2 + 1)  S.c -> O(n/2 + 1)

    map<int, int> mp; // remember map takes O(n. logn) fixed t.c 
                      //  unordered map can vary from O(1) to O(n^2)   chla to sham tak nhi to jaam tak
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    for(auto it: mp){  // bcoz it stores n/2+1 elemns only 
        if(it.second==1){
            return it.first;
        }
    }
    return -1;
}

int optimal(int n, vector<int>& arr){  // T.c -> O(1)  S.c -> O(1)
    int xor1=0;
    for(int i=0; i<n; i++){
        xor1=xor1^arr[i];
    }
    return xor1;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<optimal(n, arr);
}
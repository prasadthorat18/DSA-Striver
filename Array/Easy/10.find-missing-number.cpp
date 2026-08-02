#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MYbrutee(int n, vector<int>& arr){  //t.c-> O(n. Log n) + O(n)   S.C-> O(1)

    sort(arr.begin(), arr.end());
    int cnt=1; 
    int ans=0;
    for(int i=0; i<n-1; i++){
        if(arr[i]==cnt){
            cnt++;
        }
        else{
            ans= cnt;
            return ans;
            break;
        } 
    }
    ans=n;
    return ans;
};

int Brutee(int n, vector<int>& arr){  //t.c-> O(n) * O(n) = O(n^2)   S.C-> O(1)

    for(int i=1; i<=n; i++){
        bool flag=0;
        for(int j=0; j<n-1; j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0) return i;
    }
    return -1;
}

int better(int n, vector<int>& arr){  //t.c-> O(n) + O(n)    S.C-> O(n)
    
    int hash[n+1]={0};
    for(int i=0; i<n-1; i++){
        hash[arr[i]]++;
    }
    for(int i=1; i<=n; i++){
        if(hash[i]==0) return i;
    }
    return -1;
}

int SUM_optimal(int n, vector<int>& arr){  //t.c-> O(n)    S.C-> O(1)
    int sum= n*(n+1) / 2;
    int s2=0;
    for(int i=0; i<n-1; i++){
        s2=s2+arr[i];
    }
    return sum-s2;
}

int XOR_optimal(int n, vector<int>& arr){  //t.c-> O(n)    S.C-> O(1)

    int xor1=0;
    int xor2=0;
    for(int i=0; i<n-1; i++){
        xor1=xor1^i+1;

        xor2=xor2^arr[i];
    }
    xor1=xor1^n;
    return xor1^xor2;

}

//  xor is more optimal than sum bcoz when n=10^5 sum value goes to 10^10 its impossible to do it on cmputer so XOR
int main(){
    int n;
    cin>>n;

    vector<int> arr(n-1);
    for(int i=0; i<n-1; i++){
        cin>>arr[i];
    }
    cout<<XOR_optimal(n,arr);
}

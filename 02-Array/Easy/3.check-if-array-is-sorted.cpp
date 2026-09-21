#include<bits/stdc++.h>
using namespace std;

bool Brutee(int n, vector<int>& arr){
    bool flag=true;
    for(int i=0; i<n-1; i++){
        if(arr[i]<=arr[i+1]){
            flag=true;
        }
        else{
            flag= false;
        } 
    }
    return flag;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<Brutee(n,arr);  
}
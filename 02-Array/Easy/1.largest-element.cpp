#include<bits/stdc++.h>
using namespace std;

void Brutee(int n, vector<int>& arr){
    sort(arr.begin(), arr.end());

    cout<<arr[n-1]<<endl;
}

void optimal(int n, vector<int>&arr){
    int largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    cout<<largest<<endl;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Brutee(n,arr);  
    optimal(n,arr);
    
}
#include <bits/stdc++.h>
using namespace std;

void brutee(int n, vector<int>& arr){
    
    int temp=arr[0];
    vector<int> v;

    for(int i=1; i<n; i++){
        v.push_back(arr[i]);
    }

    v.push_back(temp);

    for(int i=0;i<n;i++){
        arr[i]=v[i];
    }
}

void optimal(int n, vector<int>& arr){
    int temp=arr[0];

    int i=0;
    for(int j=1; j<n; j++){
        arr[i]=arr[j];
        i++;
    }
    arr[n-1]=temp;
}

int main() 
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // brutee(n,arr);

    optimal(n,arr);
    for(int i=0;i<n; i++){
        cout<<arr[i]<<" ";
    }
    
}
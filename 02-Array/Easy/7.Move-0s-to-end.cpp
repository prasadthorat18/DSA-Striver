#include <bits/stdc++.h>
using namespace std;

void brutee(int n, vector<int>& arr){

    vector<int> temp(n, 0);

    int index=0;
    for(int i=0; i<n; i++){
        if(arr[i]!=0){
            temp[index]=arr[i];
            index++;
        }
    }

    for(int i=0; i<n; i++){
        arr[i]=temp[i];
    }
}

void optimal(int n, vector<int>& arr){
    //find 1st 0

    int j=-1;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }

    // swap 0 with non-zero and increment of j 
    for(int i=j+1; i<n; i++){
        if(arr[i]!=0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // brutee(n,arr);
    optimal(n,arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
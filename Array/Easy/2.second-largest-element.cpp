#include<bits/stdc++.h>
using namespace std;

void Brutee(int n, vector<int>& arr){
    sort(arr.begin(), arr.end());

    int largest=arr[n-1];
    for(int i=n-2; i>=0; i--){
        if(arr[i]!=largest){
            cout<<arr[i]<<endl;
            return;
        }
    }
    cout<<"all number is same"<<endl;
}

void better(int n, vector<int>& arr){

    int largest=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }

    int slarge=INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>slarge && arr[i]<largest){
            slarge=arr[i];
        }
    }
    // just incase if array is full of [5 5 5 5 5]
    if(slarge == INT_MIN){
        cout<<"all number is same"<<endl;
    }
    else{
        cout<<slarge<<endl;
    }
    
}

void optimal(int n, vector<int>& arr){

    int largest=arr[0];
    int slarge= INT_MIN;

    for(int i=1; i<n; i++){
        if(arr[i]>largest){
            slarge=largest;
            largest=arr[i];
        }
        else if(arr[i]>slarge && arr[i]<largest){
            slarge=arr[i];
        }
    }
    // just incase if array is full of [5 5 5 5 5]
    if(slarge == INT_MIN){
        cout<<"all number is same"<<endl;
    }
    else{
        cout<<slarge<<endl;
    }

}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Brutee(n,arr);  
    better(n,arr);
    optimal(n,arr);
    
}
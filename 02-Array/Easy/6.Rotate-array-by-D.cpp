#include <bits/stdc++.h>
using namespace std;

void brutee(int n,int d, vector<int>& arr){
    
    // Push in temp d elm.
    int temp[d];
    for(int i=0; i<d; i++){
        temp[i]=arr[i];
    }
    //swap the value of array elm. to starting
    for(int i=d; i<n ;i++){
        arr[i-d]=arr[i];
    }
    // replace temp elm. to last of original array
    int j=0;
    for(int i=n-d; i<n;i++){
        arr[i]=temp[j];
        j++;
    }
}

void RIGHTbrutee(int n,int d, vector<int>& arr){
    d=d%n;       // if d>n then wht to do?? --> THis do
    vector<int> temp;

    for(int i=n-d; i<n; i++){
        temp.push_back(arr[i]);
    }
    for(int i=n-1; i>=d; i--){
        arr[i]=arr[i-d];
    }
            
    for(int i=0; i<d; i++){
        arr[i]=temp[i];
    }
}
void optimal(int n,int d, vector<int>& arr){

    reverse(arr.begin(), arr.begin()+d);
    reverse(arr.begin()+d, arr.end());
    reverse(arr.begin(), arr.end());
}

void RIGHToptimal(int n,int d, vector<int>& arr){

    reverse(arr.begin(), arr.end()-d);
    reverse(arr.end()-d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main(){
    int n;
    cin>>n;
    int d;
    cin>>d;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // brutee(n,d,arr);
    RIGHToptimal(n,d,arr);
    for(int i=0;i<n; i++){
        cout<<arr[i]<<" ";
    }
}
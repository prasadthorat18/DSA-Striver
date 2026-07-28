#include<bits/stdc++.h>
using namespace std;

int Brutee(int n, vector<int>& arr){
    
    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    int index=0;
    for(auto it : st){
        arr[index]=it;
        index++;
    }
    return index;
}

int optimal(int n, vector<int>& arr){

    int i=0;
    for(int j=1; j<n; j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k=Brutee(n,arr);          // this gives different arra
    for(int i=0; i<k; i++){
        cout<<arr[i]<<" ";
    } 
    cout<<endl;

    int l=optimal(n,arr); 
    for(int i=0; i<l; i++){
        cout<<arr[i]<<" ";
    }
}
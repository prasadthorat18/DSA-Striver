#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MaxElement_Brute(int n,  vector<int>& arr){

    sort(arr.begin(), arr.end());  //O(n.logn)
    return arr.back();
}

int MaxElement_Optimal(int n,  vector<int>& arr){

    int maxi=arr[0];
    for(int i=0; i<n; i++){
        maxi=max(maxi, arr[i]);
    }
    return maxi;
}

int secondLargeElement_Brute(int n,  vector<int>& arr){

    sort(arr.begin(), arr.end());  //O(n.logn)
    int slarge=0;
    for(int i=n-1; i>0; i--){
        if(arr[i]>arr[i-1]){
            slarge=arr[i-1];
            break;
        }
    }
    return slarge;
}

int secondLargeElement_Better(int n,  vector<int>& arr){

    int maxi=arr[0];
    for(int i=0; i<n; i++){
        maxi=max(maxi, arr[i]);
    }
    int slarge=INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>slarge && arr[i]<maxi){
            slarge=arr[i];
        }
    }
    return slarge;
}

int secondLargeElement_Optimal(int n,  vector<int>& arr){

    int maxi=arr[0];
    int slarge=INT_MIN;

    for(int i=0; i<n; i++){
        if(arr[i]>maxi){
            slarge=maxi;
            maxi=arr[i];
        }else if(arr[i]<maxi && arr[i]>slarge){
            slarge=arr[i];
        }
    }
    return slarge;
}

void Array_is_sorted(int n,  vector<int>& arr){

    bool flag=true;
    for(int i=0; i<n-1; i++){
        if(arr[i] <= arr[i+1]){

        }
        else{
            flag=false;
        }
    }
    if(flag==true) cout<<"sorted array";
    else cout<<"unsorted array";
}

int RemoveDUplicates_Brutee(int n,  vector<int>& arr){

    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    
    int index=0;
    for(auto it : st){
        arr[index]= it;
        index++;
    }
    return index;
}
int RemoveDUplicates_Optimal(int n,  vector<int>& arr){

    int i=0; 
    for(int j=0; j<n; j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}

void leftROtateBy1_Brutee(int n, vector<int>& arr){

    int last=arr[0];

    vector<int> temp;
    for(int i=1; i<n; i++){
        temp.push_back(arr[i]);
    }
    temp[n-1]=last;

    for(int i=0; i<n; i++){
        arr[i]=temp[i];
    }
}

void leftROtateBy1_Optimal(int n, vector<int>& arr){

    int last=arr[0];

    for(int i=1; i<n; i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=last;

}

void leftROtateByK_Brutee(int n, vector<int>& arr, int k){

    vector<int> temp;
    for(int i=k; i<n; i++){
        temp.push_back(arr[i]);
    }
    for(int i=0; i<k; i++){
        temp.push_back(arr[i]);
    }

    for(int i=0; i<n; i++){
        arr[i]=temp[i];
    }
}

void LeftROtateByK_Optimal(int n, vector<int>& arr, int k){

    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.end());
    reverse(arr.begin(), arr.end());
}

void RightROtateByK_Optimal(int n, vector<int>& arr, int k){

    reverse(arr.begin(), arr.end()-k);
    reverse(arr.end()-k, arr.end());
    reverse(arr.begin(), arr.end());
}



int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;

    LeftROtateByK_Optimal(n,arr,k);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}



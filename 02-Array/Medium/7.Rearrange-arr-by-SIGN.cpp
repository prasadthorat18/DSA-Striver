#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// this is for variety 1 when pos == neg (size)  //t.c => 0(n+ n/2) s.c => O(n);
vector<int> brutee(int n, vector<int>& arr){

    vector<int>Ptemp;
    vector<int>Ntemp;
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            Ptemp.push_back(arr[i]);
        }
        else{
            Ntemp.push_back(arr[i]);
        }
    }
    
    
    for(int i=0; i<n/2; i++){
        arr[2 *i]=Ptemp[i];
        arr[2 *i + 1]=Ntemp[i];
    }
    return arr;
}

//t.c => 0(n) s.c => O(n);
vector<int> optimal(int n, vector<int>& arr){

    vector<int> ans;
    int pos=0, neg=1;
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            ans[pos]=arr[i];
            pos += 2;
        }
        else{
            ans[neg] = arr[i];
            neg += 2;
        }
    }
    return ans;
}

//  if postives != negative then ??
// ? do this bitch its very easy     //t.c => 0(2n) s.c => O(n);
vector<int> Brutte_for_variety_2(int n, vector<int>& arr){
    
    
    vector<int> pos, neg;
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }

    if(pos.size() >  neg.size()){

        for(int i=0; i<neg.size(); i++){
            arr[2 * i] = pos[i];
            arr[2 * i+1] = neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size(); i<pos.size(); i++){
            arr[index]= pos[i];
            index++;
        }   
    }
    else{
        for(int i=0; i<pos.size(); i++){
            arr[2 * i] = pos[i];
            arr[2 * i+1] = neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size(); i<neg.size(); i++){
            arr[index]= neg[i];
            index++;
        }
    }
    return arr;

}

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Brutte_for_variety_2(n, arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    // cout<<optimal(n, arr);
}
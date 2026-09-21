#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n]={};
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int num;
    cin>>num;

    bool flag=false;
    for(int i=0; i<n; i++){
        if(arr[i]==num){
            flag=true;
        } 
    }
    if(flag) cout<<"yesss hum jeet gayee!";
    else cout<<-1;
}
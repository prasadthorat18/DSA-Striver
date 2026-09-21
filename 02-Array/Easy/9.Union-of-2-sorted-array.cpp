#include <bits/stdc++.h>
using namespace std;

//using map
vector<int> brutee(int n,int m, vector<int> arr1, vector<int> arr2){
    map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[arr1[i]]++;
    }
    for(int i=0; i<m; i++){
        mp[arr2[i]]++;
    }

    vector<int> temp;
    for(auto it : mp){
        temp.push_back(it.first);
    }
    return temp;
}

//using set
vector<int> better(int n,int m, vector<int> arr1, vector<int> arr2){
    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr1[i]);
    }
    for(int i=0; i<m; i++){
        st.insert(arr2[i]);
    }

    vector<int> temp;
    for(auto it : st){
        temp.push_back(it);
    }
    return temp;
}

//2-pointer aproach  --> BACCHE 
vector<int> optimal(int n,int m, vector<int> arr1, vector<int> arr2){
    vector<int> temp;

    int i=0;
    int j=0;

    while(i<n && j<m){
        if(arr1[i] <= arr2[j]){
            if(temp.size()==0 || temp.back()!= arr1[i]){
                temp.push_back(arr1[i]);
            }
            i++;
        } else{
             if(temp.size()==0 || temp.back()!= arr2[j]){
                temp.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n){
        if(temp.size()==0 || temp.back()!= arr1[i]){
                temp.push_back(arr1[i]);
            }
            i++;
    }

    while(j<m){
        if(temp.size()==0 || temp.back()!= arr2[j]){
                temp.push_back(arr2[j]);
            }
            j++;
    }
    return temp;
}
int main(){
    int n;
    cin>>n;

    int m;
    cin>>m;

    vector<int> arr1(n);
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }
    vector<int> arr2(m);
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }

    // vector<int> ans=better(n,m,arr1,arr2);
    // for(int i=0; i<ans.size(); i++){
    //     cout<<ans[i]<<" ";
    // }
    vector<int> ans=optimal(n,m,arr1,arr2);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

}
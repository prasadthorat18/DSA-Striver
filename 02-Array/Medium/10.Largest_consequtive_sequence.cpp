#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool ls(int n, vector<int> arr, int num){

    for(int i=0; i<n; i++){
        if(arr[i] == num){
            return true;
        }
    }
    return false;

}
int bruteee(int n, vector<int>& arr){

    int maxlength=1;
    for(int i=0; i<n; i++){
        int x=arr[i];
        int cnt=1;

        while(ls(n,arr, x+1) == true){
            x = x+1;
            cnt++;
        }
        maxlength = max(maxlength, cnt);
    }
    return maxlength;
}

int better(int n, vector<int>& arr){

    sort(arr.begin(), arr.end());

    int longest=1;
    int cnt=0; 
    int lastSmaller=INT_MIN;

    for(int i=0; i<n; i++){
        if(arr[i]-1 == lastSmaller){
            cnt++;
            lastSmaller=arr[i];
        }
        else if(arr[i] != lastSmaller){
            cnt=1;
            lastSmaller=arr[i];
        }
        longest = max(cnt, longest);
    }
    return longest;
}

int optimal(int n, vector<int>& arr){

    if(n==0) return 0;
    int longest=0;

    unordered_set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }

    for(auto it : st){
        
        if(st.find(it-1) == st.end()){
            int cnt=1;
            int x= it;

            while(st.find(x+1) != st.end()){
                cnt++;
                x= x+1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
int main() 
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<optimal(n,arr);
}
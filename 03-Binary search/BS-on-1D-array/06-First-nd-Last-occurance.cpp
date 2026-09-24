#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& arr,int n, int x){

    int first=-1;
    int last= -1;

    for(int i=0; i<n; i++){
        if(arr[i] == x){
            if(first == -1 ) first = i;
            last = i;
        }
    }
    return {first, last};
}

// BETTER --> USING lOWER BOUND AND UPPER BOUND
int lowbound(vector<int>& arr,int n, int x){
    int low=0;
    int high=n-1;
    int ans = n;

    while(low <= high){
        int mid = (low + high)/2;

        if(arr[mid] >= x){
            ans=mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int uppBound(vector<int>& arr,int n, int x){
    int low=0;
    int high=n-1;
    int ans1 = n;

    while(low <= high){
        int mid = (low + high)/2;

        if(arr[mid] > x){
            ans1=mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans1;
}

int lowbound_shorthand(vector<int>& arr, int target){

    int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    return lb;
}

int uppBound_shorthand(vector<int>& arr, int target){

    int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    return ub;
}

vector<int> searchRange_BETTER(vector<int>& arr,int n, int x){
    int lb=lowbound(arr,n, x);
    int ub=uppBound(arr,n,x);

    if(lb == n || arr[lb] != x){
        return {-1,-1};
    }

    return{lb, ub};
}


// OPTIMAL USING PLANE [ BS ]
int FirstOccurnace(vector<int>& arr, int target){
    int n= arr.size();

    int low=0; int high=n-1;
    int first = -1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] == target){
            first = mid;
            high = mid -1;
        }
        else if(arr[mid] < target){
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }
    return first;
}

int LastOccurnace(vector<int>& arr, int target){
    int n= arr.size();

    int low=0; int high=n-1;
    int last = -1;

    while(low <= high){

        int mid = (low +high) / 2;

        if(arr[mid] == target){
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < target){
            low = mid +1;
        }
        else{
            high = mid - 1;
        }
    }
    return last;
}

vector<int> searchRange(vector<int>& arr, int target) {
    int n= arr.size();
    int first=FirstOccurnace(arr,target);

    if(first == -1) return {-1, -1}; // this is important bcoz we eliminate using extra (log n) time bcoz if no first occurnace then how can last occurance will be there

    int last = LastOccurnace(arr, target);

    return {first, last};

}
int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;

    vector<int> result = searchRange(arr,n,x);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
}
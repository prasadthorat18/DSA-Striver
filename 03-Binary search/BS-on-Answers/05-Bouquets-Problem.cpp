#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool Possible(vector<int>& bloomDay,int day, int m, int k){
    int n = bloomDay.size();

    int cnt = 0;
    int bqt = 0;
    for(int i=0; i<n; i++){

        if(bloomDay[i] <= day){
            cnt++;
        }
        else{
            bqt = bqt + (cnt / k);
            cnt = 0;
        }
    }
    bqt = bqt + (cnt / k);
    if( bqt >= m) return true;
    else return false;
}

// Bruteee -> T.C = [ O(n * maxi-mini+1 )]
int minDays(vector<int>& bloomDay, int m, int k) {
    int n= bloomDay.size();

    long long impossible =  1LL * m*k;  //  1LL use to convert a int in long long to svoid overflow
    if(impossible > n) return -1;

    int mini = *min_element(bloomDay.begin(), bloomDay.end());
    int maxi = *max_element(bloomDay.begin(), bloomDay.end());

    for(int i=mini; i<=maxi; i++){
        if(Possible(bloomDay, i, m , k)) return i;
    }
    return -1;
}



// optimal -> T.C = 0[n * log( maxi-mini+1 )]
int minDays_BS(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();

    long long impossible =  1LL * m*k;  //  1LL use to convert a int in long long to svoid overflow
    if(impossible > n) return -1;

    int mini = *min_element(bloomDay.begin(), bloomDay.end());
    int maxi = *max_element(bloomDay.begin(), bloomDay.end());

    int low = mini;
    int high = maxi;
    
    while( low <= high){
        int mid = low + (high - low)/2;

        if(Possible(bloomDay, mid, m, k)){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
    
}

int main(){
    int n;
    cin>>n;

    vector<int> bloomDay(n);
    for(int i=0; i<n; i++){
        cin>>bloomDay[i];
    }
    int m; cin>>m;
    int k; cin>>k;

    cout<<minDays_BS(bloomDay,m, k);
}
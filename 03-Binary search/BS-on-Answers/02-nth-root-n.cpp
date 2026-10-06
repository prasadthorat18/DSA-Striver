#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Root(int N, int M){

    int ans = 1;
    for(int i=0; i<N; i++){
        ans = ans * M;
    }
    return ans;
}


int NthRoot(int N, int M){

    for(int i=1; i<=M; i++){

        if(Root(N,i) == M) return i;
    }
    return -1;
}
// opitmal approach -> Binary search

int Root_BS(int mid, int N, int M){

    long long ans = 1;
    for(int i=0; i<N; i++){
        ans = ans * mid;
        if(ans > M) return 2;
    }
    if(ans == M) return 1;
    return 0;
}

int NthRoot_BS(int N, int M){

    int low = 1;
    int high = M;

    while(low <= high){

        int mid = (low + high) / 2;

        int result = Root_BS(mid, N, M);
        if( result == 1) return mid;

        else if(result == 2){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}


int main(){
    int N;
    cin>>N;

    int M;
    cin>>M;


}
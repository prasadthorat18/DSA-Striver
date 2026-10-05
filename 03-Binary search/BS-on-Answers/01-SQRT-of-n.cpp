#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Using_maths_Library(int x){

    return sqrt(x);
    return pow(x, 0.5);
}

int Brutee_LS(int x){

    for(int i=1; i<=x; i++){
        if(x == i*i) return i;
        else if(i*i > x) return i-1;
    }
    
    return -1;
}

int optimal_BS(int x){

    int low =1 ;
    int high = x;

    while(low <= high){
        long long mid = low + (high - low) / 2;

        long long val = mid * mid ;

        if (val <= x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}

int main(){
    int x;
    cin>>x;

}
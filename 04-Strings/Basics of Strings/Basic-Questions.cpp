#include<bits/stdc++.h>
using namespace std;

string reverse(string &s){

    int start = 0;
    int end = s.size() - 1;
    while(start < end){
        swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}

int StringLength(string &s){
    int size = 0;
    while(s[size] != '\0'){
        size++;
    }
    return size;
}

bool pallindrome(string &s){
    int st = 0;
    int end = s.size()-1;

    while(st < end){
        if(s[st] != s[end]) return false;
        st++;
        end--;
    }
    return true;

}

int main(){

    string s;
    cin>> s;


    cout<<reverse(s)<< endl;
    cout<<StringLength(s)<< endl;
    cout<<pallindrome(s)<< endl;

}
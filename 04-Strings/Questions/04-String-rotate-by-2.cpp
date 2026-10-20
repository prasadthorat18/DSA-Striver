#include<bits/stdc++.h>
using namespace std;


void rotateClockwise(string &s){
    int n = s.size();
    char last = s[n-1];
    for(int i=n-1; i>0; i--){
        s[i] = s[i-1];
    }
    s[0]= last;
}

void rotateAntiClockwise(string &s){
    int n = s.size();
    char first = s[0];
    for(int i=1; i<n; i++){
        s[i-1] = s[i];
    }
    s[n-1]= first;
}

bool isRotated(string& s1, string& s2) {
    
    if(s1.size() != s2.size()) return false;

    string clockwise = s1;
    string anticlockwise = s1;

    rotateClockwise(clockwise);
    rotateClockwise(clockwise);

    if(clockwise == s2) return true;

    rotateAntiClockwise(anticlockwise);
    rotateAntiClockwise(anticlockwise);

    if(anticlockwise == s2) return true;

    return false;
}


int main(){
    string s1;
    cin>> s1;
    string s2;
    cin>> s2;

    cout<<isRotated(s1, s2);
}
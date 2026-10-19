#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) {
    // creating vectors to store count
    vector<int> lower(26,0);
    vector<int> upper(26,0);

    // Frequency update
    for(int i=0; i<s.size(); i++){
        if(s[i] >= 'a'){
            lower[s[i] - 'a']++;
        }
        else{
            upper[s[i] - 'A']++;
        }
    }

    // if char present even times add directly in ans 
    // else add odd-1 
    int cnt = 0;
    bool odd = false;
    for(int i=0; i<26; i++){
        if(lower[i] % 2 == 0){
            cnt += lower[i];
        }
        else{
            cnt += lower[i]-1;
            odd=true;
        }
    }
    for(int i=0; i<26; i++){
        if(upper[i] % 2 == 0){
            cnt += upper[i];
        }
        else{
            cnt += upper[i]-1;
            odd=true;
        }
    }

    if(odd) return cnt + 1;  // if any odd char count in string add+1 in ans

    else return cnt;
    
}

int main(){
    string s;
    cin>> s;

    cout<<longestPalindrome(s);

}
#include<bits/stdc++.h>
using namespace std;

// pangram means -> a to z sagle letters present ahet ki nahii

bool checkIfPangram(string s) {

    vector<int> ans(26,0);
    int index = 0;
    while(index < s.size()){
        ans[s[index]-'a']++;
        index++;
    }

    for(int i=0; i<26; i++){
        if(ans[i] == 0) return false;
    }
    return true;
    
}

int main(){
    string s1;
    cin>> s1;


    cout<<checkIfPangram(s1);
}
#include<bits/stdc++.h>
using namespace std;

// bruteee -> O(n^2)
string sortString(string &s) {
    // code here
    sort(s.begin(), s.end());
    return s;
}

string sorting_optimal(string &s){

    vector<int> alpha(26,0);
    for(int i=0; i<s.size(); i++){
        alpha[s[i]-'a']++;
    }

    string ans;
    for(int i=0; i<26; i++){

        char ch = 'a' + i ;

        while( alpha[i]--){
            ans += ch;
        }
    }
    return ans;
}

int main(){
    string s;
    cin>> s;

    cout<<sorting_optimal(s);

}
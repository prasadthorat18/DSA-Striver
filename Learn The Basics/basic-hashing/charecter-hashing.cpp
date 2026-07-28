#include<bits/stdc++.h>
using namespace std;

int main(){
// charector hashing

    string s;
    cin>>s;

    //precompute
    int hash3[26]={0};  //if only lowercase letters
    for(int i=0; i<s.size(); i++){
        hash3[s[i]-'a'] ++;
    }

    // int hash3[256]={0};  //if uppercase + lowercase letters
    // for(int i=0; i<s.size(); i++){
    //     hash3[s[i]] ++;
    // }
    
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        //fetch
        cout<<hash3[c-'a']<<endl; //lowercase
        // cout<<hash3[c]<<endl; //uppeacse + lowercase   

    }
    return 0;
}
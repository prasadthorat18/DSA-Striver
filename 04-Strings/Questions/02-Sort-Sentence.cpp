#include<bits/stdc++.h>
using namespace std;

string sortSentence(string s) {

    vector<string> ans(10);
    string temp;
    int cnt =0;
    
    int i = 0;
    while( i < s.size() ){
        if(s[i] == ' '){
            int pos = temp[temp.size()-1] - '0';
            temp.pop_back();
            ans[pos] = temp;
            temp.clear();
            cnt ++;
        }
        else{
            temp += s[i];
        }
        i++;
    }
    int pos = temp[temp.size()-1] - '0';
    temp.pop_back();
    ans[pos] = temp;
    temp.clear();
    cnt ++;

    for(int i=1; i<=cnt; i++){
        temp += ans[i];
        temp += ' ';
    }
    temp.pop_back();
    
    return temp;
}

int main(){
    string s;
    getline(cin, s);

    cout<<sortSentence(s);

}
#include<bits/stdc++.h>
using namespace std;

void print1(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void print2(){
    for(int i=0; i<5; i++){
        for(int j=0; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void print3(){
    for(int i=1; i<=5; i++){
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void print4(){
    for(int i=1; i<=5; i++){
        for(int j=1; j<=i; j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void print5(){
    for(int i=5; i>=0; i--){
        for (int j=0; j<i; j++ ){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void print6(){
    for(int i=5; i>=0; i--){
        for (int j=1; j<=i; j++ ){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void print7(){

    for(int i=0; i<4; i++){
        // space
        for(int j=i; j<4-1; j++){
            cout<<" ";
        }
        //star
        for(int j=1; j<=2*i+1; j++){
            cout<<"*";
        }

        // space
        for(int j=i; j<4-1; j++){
            cout<<" ";
        }
        cout<<endl;
    }           
}

void print8(){
    for(int i=4; i>0; i--){
        //space
        for(int j=4-i; j>0; j-- ){
            cout<<" ";
        }
        //stars
        for(int j=0; j<i*2-1; j++){
            cout<<"*";
        }

        //space
        for(int j=4-i; j>0; j-- ){
            cout<<" ";
        }
        cout<<endl;
    }
}

void print9(){

     for(int i=0; i<4; i++){
        // space
        for(int j=i; j<4-1; j++){
            cout<<" ";
        }
        //star
        for(int j=1; j<=i*2+1; j++){
            cout<<"*";
        }
        // space
        for(int j=i; j<4-1; j++){
            cout<<" ";
        }
        cout<<endl;
    }
    for(int i=4; i>0; i--){
        //space
        for(int j=4-i; j>0; j-- ){
            cout<<" ";
        }
        //stars
        for(int j=0; j<i*2-1; j++){
            cout<<"*";
        }

        //space
        for(int j=4-i; j>0; j-- ){
            cout<<" ";
        }
        cout<<endl;
    }
}

void print10(){
    for(int i=0; i<5; i++){
        for(int j=0; j<=i; j++){
            cout<<("* ");
        }
        cout<<endl;
    }
    for(int i=4; i>0; i--){
        for(int j=0; j<i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void print11(){

    int num=1;
    for(int i=0; i<5; i++){
        if(i%2==0){
            num=1;
        }
        for(int j=0; j<=i; j++){
            cout<<num<<" ";
            num=1-num;
        }
        cout<<endl;
    }
}

void print12(){
    int space=6;
    for(int i=1; i<5; i++){
        //number
        for(int j=1; j<=i; j++){
            cout<<j;
        }
        //space
        for(int j=space; j>0; j--){
            cout<<" ";
            
        }
        //number
        for(int j=i; j>=1; j--){
            cout<<j;
        }
        cout<<endl;
        space -= 2;
    }
}

void print13(){

    int cnt=1;
    for(int i=0; i<5; i++){
        for(int j=0; j<=i; j++){
            cout<<cnt<<" ";
            cnt++;
        }
        cout<<endl;
    }
}

void print14(int n){
    for(int i=0; i<n; i++){

        for( char ch='A'; ch<='A'+i; ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void print15(){
    for(int i=5; i>0; i--){
        for(char ch='A'; ch<'A'+i; ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
} 

void print16(){
    for(int i=0; i<5; i++){
        char ch='A'+i;
        for(int j=0; j<=i; j++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void print17(){

    for(int i=0; i<5; i++){
        // space
        for(int j=i; j<5-1; j++){
            cout<<" ";
        }
        //chars
        char ch='A';
        int breakpoint = (2*i+1)/2;
        for(int j=1; j<=i*2+1; j++){
            cout<<ch;
            if(j<=breakpoint) ch++;
            else ch--;
        }
        // space
        for(int j=i; j<5-1; j++){
            cout<<" ";
        }
        cout<<endl;
    }           
}

void print18(){
    for(int i=0; i<5; i++){
        for(char ch='E'-i; ch<='E'; ch++ ){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void print19(){
    
}
int main(){
    // int n;
    // cin>>n;
    print18();
}
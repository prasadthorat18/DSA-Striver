#include<bits/stdc++.h>
using namespace std;


int main(){

    // Char Array

    char arr[] = {'A','p','p','l','e'};
    cout<<arr<<endl;

    for(int i=0; i<5; i++){
        cout<<arr[i];
    }
    cout<<endl;

    char arr1[20];
    cin>> arr1; //PrasadisNotGoodAtAnything
    arr1[2] = '\0';
    cout<< arr1<<endl;   //Pr



    // string

    string s = "rohit";
    cout<< s<<endl;

    //1. string space prblm  --> when intialize its okay
    string s1="Prasad Thorat";
    cout<< s1 <<endl;
    
    // --> when user gives input its problematic
    string s2;  
    // so instead of cin we use getline here
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s2);
    cout<<s2<< endl;

    // 2. size(), concatenate, add/delete char

    cout<<"size of s1: "<<s.size() << endl;

    string s3 = "laduuuuu";
    string s4 = "Prasad";
    string s5 = s3+ s4;
    cout<< s5<<endl;

    s3.push_back('T');
    cout<< s3 << endl;
    s4.pop_back();
    cout<< s4 << endl;

    // 3. Problem of double quotes and escp

    // string s6 ="rohit is a "Good" boy";   --> throws a error
    string s6 ="rohit is a \"Good\" boy";    // --> \(escp) is used to ignore its next upcoming element
    cout<< s6 <<endl;

    cout<<"\\";

}
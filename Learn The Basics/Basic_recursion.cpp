#include<bits/stdc++.h>
using namespace std;

//1. Print name N times
void fn1(int i,int n){
    if(i>n){
        return;
    }
    cout<<"Bubbu"<<endl;
    i++;
    fn1(i,n);
}

//2. Print from 1 to N 
void fn2(int i, int n){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    
    fn2(i+1,n);
}

//3. Print from N to 1
void fn3(int n){
    if(n<1){
        return;
    }
    cout<<n<<" ";
    
    fn3(n-1);
}

// 4. Print 1 to N using (BACKTRACKING)
void fn4(int n){
    if(n<1){
        return;
    }
    fn4(n-1);
    cout<<n<<" ";
}

// 5. Print from N to 1 using (BACKTRACKING)
void fn5(int i, int n){
    if(i>n){
        return;
    }
    fn5(i+1, n);
    cout<<i<<" ";
}

//6. sum of first N numbers
int sum=0;
void fn6(int i, int n){
    
    if(i>n){
        return;
    }
    sum=sum+i;
    fn6(i+1, n);
}
// his parameterized way
void fn6_1(int i, int sum){
    if(i<1){
        cout<<sum<<endl;
        return;
    }
    fn6_1(i-1, sum+i);
}
//his functional way
int fn6_2(int n){
    if(n==0){
        return 0;
    }
    return n + fn6_2(n-1);
}

//7. factorial of given number
int total=1;
void fn7(int n){
    if(n<1){
        return;
    }
    fn7(n-1);
    total=total*n;
}

//his parameterized way
void fn7_1(int i, int total){
    if(i<2){
        cout<<total;
        return;
    }
    fn7_1(i-1, total*i);
}
//his functional way
int fn7_2(int n){
    if(n==1){
        return 1;
    }
    return n * fn7_2(n-1);
}

//8. reverse the array using recursion

//using 2 pointers
void fn8_1(int l, int r, int arr2[]){
    if(l>=r) return;

    swap(arr2[l], arr2[r]);
    fn8_1(l+1, r-1, arr2);
}

//using 1 pointer 
void fn8_2(int i, int n, int arr2[]){
    if(i>=n/2) return;

    swap(arr2[i], arr2[n-i-1]);
    fn8_2(i+1,n,arr2);
}

// 9. check if string is pallinddrome or not 
bool fn9(int i, string &s){
    if(i>=s.size()/2) return true;
    
    if(s[i]!=s[s.size()-i-1]) return false;

    return fn9(i+1,s);
}
// 10. fibonacii number
int fn10(int n){
    int f=0;
    if(n<=1) return n;

    int last=1; int slast=0;
    for(int i=2; i<=n; i++){
        int ans= last + slast;
        slast = last;
        last= ans;
    }
    return last;
}

//by using recursion
int fn10_1(int n){
    if(n<=1) return n;

    int last=fn10_1(n-1);
    int slast=fn10_1(n-2);

    return last+slast;

}
int main(){
    int arr[]= {10,20,30,40,50};
    
    int m=sizeof(arr)/sizeof(arr[0]);

    // for(int i=m-1; i>=0; i--){
    //     cout<<arr[i]<<" ";
    // }
    
    //optimal array reverse

    // int i=0; int j=m-1;
    // while(i<=j){
    //     int temp=arr[i];
    //     arr[i]=arr[j];
    //     arr[j]=temp;
    //     i++;
    //     j--;
    // }
    // for(int i=0; i<m; i++){
    //     cout<<arr[i]<<" ";
    // }

    int n;
    cin>>n;
    fn1(1,n);  
    
    fn2(1,n);
    cout<<endl;

    fn3(n);
    cout<<endl;

    fn4(n);
    cout<<endl;

    fn5(1,n);
    cout<<endl;

    fn6(1,n); cout<<sum<<endl;
    fn6_1(n,0);
    int result=fn6_2(n); cout<<result<<endl;

    fn7(n); cout<<total<<endl;
    fn7_1(n,1); cout<<endl;
    int result2=fn7_2(n); cout<<result2<<endl;

    int arr2[n];
    for(int i=0; i<n; i++){
        cin>>arr2[i];
    }

    // fn8_1(0, n-1, arr2);

    fn8_2(0, n, arr2);
    for(int i=0; i<n; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    string s = "bhakhb";
    cout<<fn9(0,s); cout<<endl;

    int result3=fn10(n);
    cout<<result3<<endl;
    
    int result4=fn10_1(n);
    cout<<result4<<endl;
    
}



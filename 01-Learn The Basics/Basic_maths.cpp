#include <bits/stdc++.h>
using namespace std;

int countnum(int n){
    int cnt=0;
    while(n>0){
        cnt++;
        n=n/10;
    }
    return cnt;
}

int reverse(int n){
    int reversed=0;
    while(n!=0){
        int lstdigit = n % 10;
        reversed = reversed * 10 + lstdigit;
        n = n/10;
    }
    if(reversed>INT_MAX || reversed < INT_MIN){
        return 0;
    }

    return reversed;
}

int pallindrome(int n){
    int reversed=0;
    int final=n;
    while(n!=0){
        int lstdigit = n % 10;
        reversed = reversed * 10 + lstdigit;
        n = n/10;
    }
    if(reversed>INT_MAX || reversed < INT_MIN){
        return 0;
    }
    if(reversed==final) return true;
    else return false;

}

int bruteGCD(int n1, int n2){
    int gcd=1;
    for(int i=1; i<=min(n1,n2); i++){
        if(n1%i==0 && n2%i==0){
            gcd=i;
        }
    }
    return gcd;
}

int optimalGCD(int n1, int n2){
    //Euclidean Algorithmn
    // The Euclidean Algorithm is a method for finding the greatest common divisor (GCD) of two numbers. It operates on the principle that the GCD of two numbers remains same even if the smaller number is subtracted from the larger number.

    // To find the GCD of n1 and n2 where n1 > n2:
    // 1. Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
    // 2. Once one becomes 0, the other is the GCD of the original numbers.

                    // Example:
                    // n1 = 20, n2 = 15

                    // gcd(20, 15) = gcd(20 - 15, 15) = gcd(5, 15)
                    // gcd(5, 15)  = gcd(15 - 5, 5)  = gcd(10, 5)
                    // gcd(10, 5)  = gcd(10 - 5, 5) = gcd(5, 5)
                    // gcd(5, 5)   = gcd(5 - 5, 5)  = gcd(0, 5)
    
    while(n1>0 && n2>0){

        if(n1>n2){
            n1=n1-n2;
        }
        else{
            n2=n2-n1;
        }
    }

    if( n1==0){
        return n2;
    }
    
        return n1;
}

int armstrong(int n){

    // this is an alternative way of finding count
    int k= to_string(n).length();  // fuck u striver


    int original=n;
    int reduce=n;
    int cnt=0;

    while(reduce>0){
        cnt++;
        reduce=reduce/10;
    }
    int ans=0;
    while(n>0){
        int lstdigit=n%10;
        ans=ans+pow(lstdigit,cnt);
        n=n/10;
    }
    if(original==ans) return true;
    else return false;
}

void divisors(int n){
    
    for(int i=1; i<=n; i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}
// Mokar Gandmasti (array mdhe output kas aantat)
class divisorsARR{
    public:
        vector<int> getdivisors(int n){
            vector<int> arr;
            for(int i=1; i<=n; i++){
                if(n%i==0){
                arr.push_back(i);
                }
            }
            return arr;
        }
};

int brutePRIME(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cnt++;
        }
    }
    if(cnt==2) return true;
    else return false;
}

int optimalPRIME(int n){
    int cnt=0;
    for(int i=1; i<=sqrt(n); i++){ 
        //if n=36 iteration go until 6 bcoz next upcoming (9 * 4) is already counted, (12 * 3) is already counted so sqrt(n)is okauy 
        if(n%i==0){
            cnt++;   //if i=4  36%4=0 cnt++;

            if(n/i != i){ // here 9 is also na paired so hyacha count ghen pan imp ahe so 36/4=9 and 9!=4  cnt++;
                cnt++;
            }
        }
    }
    if(cnt==2) return true;
    else return false;
}

int main(){
    // int n1,n2;
    // cin>>n1>>n2;

    // divisorsARR obj;
    // vector<int> sol=obj.getdivisors(n);
    // for(int val : sol){
    //     cout<<val<<endl;
    // }

    int n; cin>>n;
    int result=optimalPRIME(n);
    cout<<result;
    return 0;

}
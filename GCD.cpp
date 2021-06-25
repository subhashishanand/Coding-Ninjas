// Calculate and return GCD of two given numbers x and y. Numbers are within range of Integer.
// Using euclid algorithm.


#include<iostream>
using namespace std;

int GCD(int a,int b){
    if(b==0)
    return a;
    return GCD(b,a%b);
}

int main(){
    int a,b;
    cin>>a>>b;
    if(a>b){
        cout<<GCD(a,b)<<endl;
    }else{
        cout<<GCD(b,a)<<endl;
    }
    return 0;
}
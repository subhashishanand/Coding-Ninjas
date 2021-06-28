#include<iostream>
using namespace std;

int GCD(int a,int b){
    if(b==0){
        return a;
    }
    return GCD(b,a%b);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        string b;
        cin>>b;
        if(a==0)
        {
            cout<<b<<endl;
            continue;
        }
        int bmoda=0;
        for(int i=0;i<b.length();i++){
            bmoda=((bmoda*10)%a+b[i]-'0')%a;
        }
        cout<<GCD(a,bmoda)<<endl;
    }
    return 0;
}
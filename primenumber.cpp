// Given a number N, find number of primes in the range [1,N].

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

void modify(vector<bool> &vec,int k){
    for(int i=k*k;i<vec.size();i+=k){
        vec[i]=false;
    }
}

int main(){
    int n;
    cin>>n;
    vector<bool> vec(n+1,true);
    vec[0]=false;
    vec[1]=false;
    int sq=sqrt(n);
    for(int i=2;i<=sq;i++){
        if(vec[i]){
            modify(vec,i);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vec[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
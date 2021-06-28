#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    int mod= pow(10,9)+7;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<bool> prime(n+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<=sqrt(n);i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        vector<int> p(n+1,0);
        long long ans=1;
        for(int i=2;i<=n;i++){
            if(prime[i]){
                for(int j=i;j<=n;j=j*i){
                    p[i]+=n/j;
                }
                ans=ans*(p[i]+1)%mod;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
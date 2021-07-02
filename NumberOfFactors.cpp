#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int main(){
    int maxno=pow(10,6);
    vector<int> dp(maxno+1,0);
    vector<bool> prime(maxno+1,true);
    prime[0]=false;
    prime[1]=false;
    for(int i=0;i<=sqrt(maxno);i++){
        if(prime[i]){
            for(int j=i*i;j<=maxno;j=j+i){
                prime[j]=false;
            }
        }
    }
    for(int i=0;i<=maxno;i++){
        if(prime[i]){
        	for(int j=i;j<=maxno;j=j+i){
            	dp[j]++;
        	}
        }
    }
    int t;
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        int ans=0;
        for(int i=a;i<=b;i++){
            if(dp[i]==n){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
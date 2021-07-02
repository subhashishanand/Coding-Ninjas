 #include<iostream>
#include<vector>
#include<algorithm>
#define mod 1000000007
using namespace std;

int main(){
    int maxele=750000;
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> values(maxele+1,0);
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            values[a]++;
        }
        for(int i=0;i<=maxele;i++){
            if(values[i]!=0){
                for(int j=i*2;j<=maxele;j=j+i){
                    if(values[j]!=0)
                    	values[j]=((long long)values[j]+values[i])%mod;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<=maxele;i++){
            ans=(ans+values[i])%mod;
        }
        cout<<ans<<endl;
    }
	return 0;
}
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
	// Write your code here
    vector<bool> prime(101,true);
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<=sqrt(100);i++){
        if(prime[i]){
            for(int j=i*i;j<=100;j=j+i){
                prime[j]=false;
            }
        }
    }
    vector<int> cubeFreeNumber(1000001,0);
    for(int i=2;i<=100;i++){
        if(prime[i]){
            for(int j=i*i*i;j<=1000000;j=j+i*i*i){
                cubeFreeNumber[j]=-1;
            }
        }
    }
    int ans=1;
    for(int i=1;i<=1000000;i++){
        if(cubeFreeNumber[i]!=-1){
            cubeFreeNumber[i]=ans;
            ans++;
        }
    }
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        if(cubeFreeNumber[n]==-1){
            cout<<"Case "<<i<<": Not Cube Free"<<endl;
        }else{
            cout<<"Case "<<i<<": "<<cubeFreeNumber[n]<<endl;
        }
    }
	return 0;
}
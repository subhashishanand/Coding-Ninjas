#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> helper(int n){
    vector<int> prime;
    int m=sqrt(n);
    if(n%2==0){
            prime.push_back(2);
            while(n%2==0){
                n=n/2;
            }
    }
    for(int i=3;i<=m;i+=2){
        if(n%i==0){
            prime.push_back(i);
            while(n%i==0){
                n=n/i;
            }
            if(n==1){ 
                break;
            }
        }
    }
    if(n>2){
        prime.push_back(n);
    }
    return prime;
}

int main() {
    int n;
    cin>>n;
    vector<bool> dp(n+1,false);
    for(int i=n;i>0;i--){
        if(i==1){
            cout<<"1 ";
        }
        if(dp[i]==false){
            vector<int> values=helper(i);
            vector<int> no;
            for(int j=0;j<values.size();j++){
                for(int k=values[j];k<=n;k+=values[j]){
                    if(dp[k]==false){
                        no.push_back(k);
                        dp[k]=true;
                    }
                }
            }
            sort(no.begin(),no.end(),greater<int>());
            for(int j=0;j<no.size();j++){
                cout<<no[j]<<" ";
            }
        }
    }
}
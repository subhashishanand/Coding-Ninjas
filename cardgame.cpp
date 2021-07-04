#include<iostream>
#include<vector>
#include<math.h>
#include<utility>
#define pp pair<int,int>
#define int long long
using namespace std;


bool check(vector<pp>& temp,vector<pp> fac){
    for(int i=0;i<fac.size();i++){
        if(temp[i].second<fac[i].second){
            return false;
        }
    }
    return true;
}

int32_t main(){
    int maxk=pow(10,9);
    int n,k;
    cin>>n>>k;
    vector<pp> fac;
    for(int i=2;i<=maxk;i++){
        if(k%i==0){
            int ans=0;
            while(k%i==0){
                k=k/i;
                ans++;
            }
            fac.push_back(make_pair(i,ans));
            if(k==1){
                break;
            }   
        }
    }
    vector<pp> temp(fac.size());
    for(int i=0;i<fac.size();i++){
        temp[i].first=fac[i].first;
        temp[i].second=0;
    }
    vector<int> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int si=0,ei=0;
    int ans=0;
    while(si<n){
        if(check(temp,fac)){
            //discard si
            ans+=n-ei+1;
            int k=input[si];
            for(int i=0;i<temp.size();i++){
                while(k%temp[i].first==0){
                    k=k/temp[i].first;
                    temp[i].second--;
                }
            }
            si++;
        }else{
            //insert ei;
            if(ei>=n){
                break;
            }
            int k=input[ei];
            for(int i=0;i<temp.size();i++){
                while(k%temp[i].first==0){
                    k=k/temp[i].first;
                    temp[i].second++;
                }
            }
            ei++;
        }
    }
    cout<<ans<<endl;
	return 0;
}
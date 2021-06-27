#include<iostream>
using namespace std;
#define pp pair<int,int>

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

pp extendEuclidAlgorithm(int a,int b){
    if(b==0){
        return make_pair(1,0);
    }
    pp p1=extendEuclidAlgorithm(b,a%b);
    return make_pair(p1.second,p1.first-(a/b)*p1.second);
}

int modulusInverse(int a,int M){
    int x=extendEuclidAlgorithm(a,M).first;
    return (x%M+M)%M;
}

int main(){
	int t;
    cin>>t;
    while(t--){
        int a,b,d;
        cin>>a>>b>>d;
        int g=gcd(a,b);
        if(d%g!=0){ 
            cout<<0<<endl;
            continue;
        }
        a=a/g;
        b=b/g;
        d=d/g;
        int ymin=(d%a*modulusInverse(b,a))%a;
        if(ymin>(d/b)){
            cout<<0<<endl;
        }else{
            int n=((d/b)-ymin)/a +1;
            cout<<n<<endl;
        }
    }
	return 0;
}
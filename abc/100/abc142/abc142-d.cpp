#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    ll a,b,g;
    scanf("%lld%lld",&a,&b);
    g=gcd(a,b);
    vector<ll> ans,div;
    ll r=sqrt(g);
    for(ll i=1;i<=r;i++){
        if(g%i==0){
            div.push_back(i);
            if(i*i!=g){
                div.push_back(g/i);
            }
        }
    }
    sort(div.begin(),div.end());
    for(int i=0;i<div.size();i++){
        int flag=1;
        for(int j=0;j<ans.size();j++){
            if(gcd(div[i],ans[j])!=1){
                flag=0;
                break;
            }
        }
        if(flag){
            ans.push_back(div[i]);
        }
    }
    printf("%ld\n",ans.size());
}
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ll n,ans=0,rn,a;
    vector<ll> v;
    scanf("%lld",&n);
    rn=sqrt(n);
    for(ll i=1;i<=rn;i++){
        if(n%i==0){
            if(i*i==n){
                v.push_back(i);
            }
            else{
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
    for(int i=0;i<v.size();i++){
        a=(n-v[i])/v[i];
        if(a&&n/a==n%a){
            ans+=a;
        }
    }
    printf("%lld\n",ans);
}
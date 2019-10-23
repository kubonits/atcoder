#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
#include<queue>
#define mod 1000000007
#define INF 1000000000000000
using namespace std;
typedef long long ll;
int main(){
    ll l,a,b,m,ans=0,ten[19]={1LL,},x;
    for(int i=1;i<19;i++){
        ten[i]=ten[i-1]*10;
    }x=0;
    scanf("%lld %lld %lld %lld",&l,&a,&b,&m);
    ans=a;
    ans%=m;
    for(ll i=1;i<l;i++){
        a+=b;
        while(ten[x]<=a){
            x++;
        }
        ans*=ten[x]%m;
        ans%=m;
        ans+=a%m;
        ans%=m;
    }
    printf("%lld\n",ans);
}
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,k,a[100001],sum,ans;
int main(){
    ll l,r;
    r=0;
    scanf("%lld %lld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sum=a[0];
    for(ll i=0;i<n;i++){
        while(r<n&&sum<k){
            r++;
            sum+=a[r];
        }
        if(sum>=k){
            ans+=n-r;
        }
        sum-=a[i];
    }
    printf("%lld\n",ans);
}
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
#include<deque>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main(){
    ll n,k,a[2000],ans=0;
    scanf("%lld %lld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++){
        ll cnt=0LL;
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                cnt++;
            }
        }
        ans+=k*cnt;
        ans%=MOD;
        for(int j=0;j<=i;j++){
            if(a[i]>a[j]){
                cnt++;
            }
        }
        ll sum=cnt;
        if(k%2==0){
            sum*=k/2LL;
            sum%=MOD;
            sum*=(k-1);
            sum%=MOD;
        }
        else{
            sum*=k;
            sum%=MOD;
            sum*=(k-1)/2LL;
            sum%=MOD;
        }
        ans+=sum;
        ans%=MOD;
    }
    printf("%lld\n",ans);
}
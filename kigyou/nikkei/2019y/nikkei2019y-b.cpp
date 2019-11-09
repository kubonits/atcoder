#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<utility>
#include<queue>
#define MOD 998244353
using namespace std;
typedef long long ll;
int main(){
    ll n,d[100000],num[100000]={},ans=1LL;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&d[i]);
        num[d[i]]++;
    }
    if(d[0]!=0||num[0]!=1){
        ans=0;
    }
    for(int i=1;i<n;i++){
        if(num[i]&&num[i-1]==0){
            ans=0LL;
        }
        for(int j=0;j<num[i];j++){
            ans*=num[i-1];
            ans%=MOD;
        }
    }
    printf("%lld\n",ans);
}
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
char s[100010];
ll ans,t[100010];
int n;

ll calc(int x){
    if(x==n){
        return 1;
    }
    ll res;
    if(s[x]=='1'){
        res=t[n-1-x];
        res%=mod;
        res+=2LL*calc(x+1);
        res%=mod;
        return res;
    }
    else{
        return calc(x+1);
    }
}
int main(){
    scanf("%s",s);
    n=strlen(s);
    t[0]=1LL;
    for(int i=1;i<=n;i++){
        t[i]=t[i-1]*3LL;
        t[i]%=mod;
    }
    printf("%lld\n",calc(0));
}
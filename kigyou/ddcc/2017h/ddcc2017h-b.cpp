/*
https://atcoder.jp/contests/ddcc2017-final/tasks/ddcc2017_final_b
*/
#include<cstdio>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    int n;
    ll z,a,b,ans=1LL;
    scanf("%d %lld",&n,&z);
    for(int i=0;i<n;i++){
        scanf("%lld",&a);
        a=gcd(a,z);
        b=gcd(ans,a);
        ans=ans/b*a;
    }
    printf("%lld\n",ans);
}
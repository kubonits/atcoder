#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    long q,h,s,d,ans=0,n,o;
    scanf("%ld %ld %ld %ld",&q,&h,&s,&d);
    scanf("%ld",&n);
    o=min(2*q,h);
    o=min(2*o,s);
    ans+=n/2*min(2*o,d);
    ans+=n%2*o;
    printf("%ld\n",ans);
}
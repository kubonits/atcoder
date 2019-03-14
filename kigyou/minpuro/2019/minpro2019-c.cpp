#include<cstdio>
using namespace std;
int main(){
    long long k,a,b,ans=1LL,l,r,mid;
    scanf("%lld %lld %lld",&k,&a,&b);
    if(b<=a+2||k<=a-3){
        printf("%lld\n",k+1);
        return 0;
    }
    ans=a;
    if((k-a+1)%2){
        ans++;
    }
    printf("%lld\n",ans+(b-a)*(k-ans+1)/2);
}
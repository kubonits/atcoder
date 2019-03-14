#include<cstdio>
using namespace std;
int main(){
    int a,b,c,d,ans=0;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    ans+=a;
    ans*=12;
    ans+=b;
    ans*=12;
    ans+=c;
    ans*=12;
    ans+=d;
    printf("%d\n",ans);
}
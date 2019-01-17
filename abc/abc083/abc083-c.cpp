#include<cstdio>
using namespace std;
int main(){
    long long x,y;
    int ans=0;
    scanf("%lld %lld",&x,&y);
    while(x<=y){
        ans++;
        x*=2;
    }
    printf("%d\n",ans);
}
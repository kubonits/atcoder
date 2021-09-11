#include<cstdio>
using namespace std;
int main(){
    int a,b,c,k,s,t;
    scanf("%d %d %d %d",&a,&b,&c,&k);
    scanf("%d %d",&s,&t);
    int ans=a*s+b*t;
    if(s+t>=k){
        ans-=c*(s+t);
    }
    printf("%d\n",ans);
}
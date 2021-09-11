#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a,b,ans=0;
    scanf("%d %d",&a,&b);
    ans=a+b;
    ans=max(a+a-1,ans);
    ans=max(ans,b+b-1);
    printf("%d\n",ans);
}
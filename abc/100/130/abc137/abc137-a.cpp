#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int a,b,ans=-100000000;
    scanf("%d%d",&a,&b);
    ans=max(ans,a+b);
    ans=max(ans,a-b);
    ans=max(ans,a*b);
    printf("%d\n",ans);
}
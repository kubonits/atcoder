#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,a,b,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        ans=max(ans,a+b);
    }
    printf("%d\n",ans);
}
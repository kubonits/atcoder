#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,ans=1000,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        ans=min(ans,a);
    }
    printf("%d\n",ans);
}
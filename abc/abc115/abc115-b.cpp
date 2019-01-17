#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,maxp=0,p[10],ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
        ans+=p[i];
        maxp=max(maxp,p[i]);
    }
    printf("%d\n",ans-maxp/2);
}
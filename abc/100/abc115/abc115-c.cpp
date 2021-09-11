#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,k,h[100000],ans=1000000000;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    sort(h,h+n);
    for(int i=0;i+k-1<n;i++){
        ans=min(ans,h[i+k-1]-h[i]);
    }
    printf("%d\n",ans);
}
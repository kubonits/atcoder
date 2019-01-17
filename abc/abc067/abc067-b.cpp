#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,k,ans=0,l[50];
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&l[i]);
    }
    sort(l,l+n);
    for(int i=0;i<k;i++){
        ans+=l[n-1-i];
    }
    printf("%d\n",ans);
}
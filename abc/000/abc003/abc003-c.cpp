#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    double r[100],ans=0;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lf",&r[i]);
    }
    sort(r,r+n);
    for(int i=n-k;i<n;i++){
        ans+=r[i];
        ans/=2;
    }
    printf("%.7f\n",ans);
}
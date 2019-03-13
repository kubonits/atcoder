#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,d[50][50],sum[101][101]={},q,p,ans,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&d[i][j]);
            sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]+d[i][j]-sum[i][j];
        }
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&p);
        ans=0;
        for(int l=1;p/l>0;l++){
            x=min(n,p/l);
            for(int j=1;j+l-1<=n;j++){
                for(int k=1;k+x-1<=n;k++){
                    ans=max(ans,sum[j+l-1][k+x-1]-sum[j+l-1][k-1]-sum[j-1][k+x-1]+sum[j-1][k-1]);
                }
            }
        }
        printf("%d\n",ans);
    }
}
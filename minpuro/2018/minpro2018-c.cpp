#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 100000000000000000
using namespace std;
typedef long long ll;
int n,two[19],bit[1000000][18],num;
ll x[18],c[18],v[18],sum[19]={},dp[1000000],f[1000000][20]={},allc,allv;
vector<int> a[20];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&x[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&c[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&v[i]);
    }
    two[0]=1;
    sum[0]=0;
    for(int i=0;i<n;i++){
        sum[i+1]=sum[i]+x[i];
    }
    for(int i=1;i<=n;i++){
        two[i]=two[i-1]*2;
    }
    for(int i=0;i<two[n];i++){
        num=i;
        for(int j=0;j<n;j++){
            bit[i][j]=num%2;
            num/=2;
        }
        num=0;
        for(int j=0;j<n;j++){
            num+=bit[i][j];
        }
        a[num].push_back(i);
    }
    for(int i=n;i>=0;i--){
        for(int j=0;j<a[i].size();j++){
            allc=0;
            allv=0;
            for(int k=0;k<n;k++){
                if(bit[a[i][j]][k]==0){
                    allc+=c[k];
                    allv+=v[k];
                }
            }
            for(int k=0;k<=i;k++){
                if(allc<=sum[k]){
                    f[a[i][j]][k]=allv;
                }
                else{
                    for(int l=0;l<n;l++){
                        if(bit[a[i][j]][l]==0){
                            f[a[i][j]][k]=max(f[a[i][j]][k],f[a[i][j]+two[l]][k]);
                        }
                    }
                }
            }
            if(i==n){
                dp[a[i][j]]=0;
            }
            else{
                dp[a[i][j]]=INF;
                for(int k=0;k<n;k++){
                    if(bit[a[i][j]][k]==0){
                        dp[a[i][j]]=min(dp[a[i][j]],dp[a[i][j]+two[k]]);
                    }
                }
                dp[a[i][j]]=max(dp[a[i][j]],f[a[i][j]][i]);
            }
        }
    }
    printf("%lld\n",dp[0]);
}
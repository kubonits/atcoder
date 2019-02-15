#include<cstdio>
#define mod 1000000007
using namespace std;
typedef long long ll;
int main(){
    int n;
    ll k,two[60],a[60][50][50]={},b[50][50]={},c[50][50],ans=0;
    scanf("%d %lld",&n,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lld",&a[0][i][j]);
        }
    }
    two[0]=1;
    for(int i=1;i<60;i++){
        two[i]=two[i-1]*2;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                for(int l=0;l<n;l++){
                    a[i][j][k]+=a[i-1][j][l]*a[i-1][l][k];
                    a[i][j][k]%=mod;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        b[i][i]=1;
    }
    for(int i=0;i<60;i++){
        if((k&two[i])){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    c[j][k]=0;
                    for(int l=0;l<n;l++){
                        c[j][k]+=b[j][l]*a[i][l][k];
                        c[j][k]%=mod;
                    }
                }
            }
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    b[j][k]=c[j][k];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+=b[i][j];
            ans%=mod;
        }
    }
    printf("%lld\n",ans);
}
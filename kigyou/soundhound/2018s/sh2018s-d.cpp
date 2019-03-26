#include<cstdio>
#include<algorithm>
#define INF 100000000000
using namespace std;
typedef long long ll;

ll dp[10][50000],l[10][50000],r[10][50000],p[10][50000],f[10][50000];
int main(){
    int h,w;
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%lld",&p[i][j]);
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%lld",&f[i][j]);
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dp[i][j]=-INF;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<h;i++){
        l[i][0]=0;
        for(int j=1;j<w;j++){
            l[i][j]=max(l[i][j-1])
        }
    }
}
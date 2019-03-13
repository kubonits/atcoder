#include<cstdio>
#include<algorithm>
using namespace std;
int n,dp[2001][2001],a[4000],b[2001],w[2001],cb[2001][2001],cw[2001][2001];
char s[4000][2];

int bitb[2001],bitw[2001];

int sumb(int i){
    int s=0;
    while(i>0){
        s+=bitb[i];
        i -= (i&-i);
    }
    return s;
}

int addb(int i,int x){
    while(i<=n){
        bitb[i]+=x;
        i+=(i&-i);
    }
}

int sumw(int i){
    int s=0;
    while(i>0){
        s+=bitw[i];
        i -= (i&-i);
    }
    return s;
}

int addw(int i,int x){
    while(i<=n){
        bitw[i]+=x;
        i+=(i&-i);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<2*n;i++){
        scanf("%s %d",s[i],&a[i]);
        if(s[i][0]=='B'){
            b[a[i]]=i;
            for(int j=0;j<=n;j++){
                cb[a[i]-1][j]=sumb(n)-sumb(a[i])+sumw(n)-sumw(j);
            }
            addb(a[i],1);
        }
        else{
            w[a[i]]=i;
            for(int j=0;j<=n;j++){
                cw[j][a[i]-1]=sumb(n)-sumb(j)+sumw(n)-sumw(a[i]);
            }
            addw(a[i],1);
        }
    }
    
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+cb[i-1][0];
        dp[0][i]=dp[0][i-1]+cw[0][i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=min(dp[i-1][j]+cb[i-1][j],dp[i][j-1]+cw[i][j-1]);
        }
    }
    printf("%d\n",dp[n][n]);
}
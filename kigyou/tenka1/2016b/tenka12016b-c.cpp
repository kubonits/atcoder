#include<cstdio>
#include<algorithm>
#include<utility>
#include<cstring>
using namespace std;
int main(){
    int n,a[30][30],x;
    char s[5];
    double p,q,dp[30][30]={},kati[31][30]={},ans=0.0;
    pair<int,int> b[30];
    scanf("%d",&n);
    scanf("%s",&s);
    p=(double)(s[0]-'0')/(double)(s[2]-'0');
    if(strlen(s)==4){
        p=(double)(s[0]-'0')/10.0;
    }
    for(int i=0;i<n;i++){
        b[i].first=0;
        b[i].second=i;
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            b[i].first-=a[i][j];
        }
    }
    sort(b,b+n);
    kati[0][0]=1.0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[b[0].second][b[i].second]==1){
                kati[i][j]+=kati[i-1][j]*(1.0-p);
                kati[i][j+1]+=kati[i-1][j]*p;
            }
            else{
                kati[i][j]+=kati[i-1][j]*p;
                kati[i][j+1]+=kati[i-1][j]*(1.0-p);
            }
        }
    }
    for(int i=0;i<n;i++){
        dp[0][i]=kati[n-1][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                kati[j][k]=0.0;
            }
        }
        kati[0][0]=1.0;
        for(int j=0;j<n;j++){
            if(b[i].second==j){
                for(int k=0;k<n;k++){
                    kati[1+j][k]=kati[j][k];
                }
            }
            else{
                for(int k=0;k<n-1;k++){
                    if(a[b[i].second][j]==1){
                        kati[j+1][k]+=kati[j][k]*(1.0-p);
                        kati[j+1][k+1]+=kati[j][k]*p;
                    }
                    else{
                        kati[j+1][k]+=kati[j][k]*(p);
                        kati[j+1][k+1]+=kati[j][k]*(1.0-p);
                    }
                }
            }
        }
        for(int j=0;j<n;j++){
            if(b[i].second>b[i-1].second){
                x=j;
            }
            else{
                x=j+1;
            }
            for(int k=n-1;k>=x;k--){
                dp[i][j]+=dp[i-1][k];
            }
            dp[i][j]*=kati[n][j];
        }
    }
    for(int i=0;i<n;i++){
        ans+=dp[n-1][i];
    }
    printf("%.9f\n",ans);
}
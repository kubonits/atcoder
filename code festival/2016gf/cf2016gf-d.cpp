#include<cstdio>
#include<cstring>
using namespace std;
int n,m,f[256]={},f2[52]={};
long long dp[52][52][52]={},dp1[52],dp2[52][52],x=-1,dp3[52][52][52]={};
char s[90001],a[4];
int main(){
    scanf("%d",&n);
    for(int i=0;i<52;i++){
        for(int j=0;j<52;j++){
            for(int k=0;k<52;k++){
                dp3[i][j][k]=-1;
            }
        }
    }
    for(int i='A';i<='Z';i++){
        f[i]=i-'A';
        f2[i-'A']=i;
    }
    for(int i='a';i<='z';i++){
        f[i]=i-'a'+26;
        f2[i-'a'+26]=i;
    }
    for(int i=0;i<n;i++){
        scanf("%s",s);
        for(int j=0;j<52;j++){
            dp1[j]=0;
            for(int k=0;k<52;k++){
                dp2[j][k]=0;
            }
        }
        m=strlen(s);
        for(int j=0;j<m;j++){
            for(int k=0;k<52;k++){
                for(int l=0;l<52;l++){
                    if(dp2[k][l]&&dp3[k][l][f[s[j]]]!=i){
                        dp3[k][l][f[s[j]]]=i;
                        dp[k][l][f[s[j]]]++;
                    }
                }
                dp2[k][f[s[j]]]+=dp1[k];
            }
            dp1[f[s[j]]]++;
        }
    }
    for(int i=0;i<52;i++){
        for(int j=0;j<52;j++){
            for(int k=0;k<52;k++){
                //printf("%c%c%c %lld\n",f2[i],f2[j],f2[k],dp[i][j][k]);
                if(x<dp[i][j][k]){
                    a[0]=f2[i];
                    a[1]=f2[j];
                    a[2]=f2[k];
                    x=dp[i][j][k];
                }
            }
        }
    }
    a[3]='\0';
    printf("%s\n",a);
}
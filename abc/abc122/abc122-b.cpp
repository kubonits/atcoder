#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int n,dp[11]={},ans=0;
    char s[11];
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]=='A'||s[i]=='C'||s[i]=='T'||s[i]=='G'){
            dp[i+1]=dp[i]+1;
            ans=max(ans,dp[i+1]);
        }
    }
    printf("%d\n",ans);
}
#include<cstdio>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;
char s[200010];
pair<int,pair<int ,int>> dp[200010];
int main(){
    int n,r[26];
    scanf("%s",s);
    n=strlen(s);
    dp[n]=make_pair(1,make_pair(0,n));
    for(int i=0;i<26;i++){
        r[i]=n;
    }
    r[s[n-1]-'a']=n-1;
    for(int i=n-1;i>=0;i--){
        dp[i]=make_pair(300000,make_pair(0,n));
        for(int j=0;j<26;j++){
            if(r[j]==n){
                dp[i]=min(dp[i],make_pair(1,make_pair(j,n)));
            }
            else{
                dp[i]=min(dp[i],make_pair(1+dp[r[j]+1].first,make_pair(j,r[j])));
            }
        }
        if(i){
            r[s[i-1]-'a']=i-1;
        }
    }
    for(int i=0;i!=n+1;i=dp[i].second.second+1){
        printf("%c",dp[i].second.first+'a');
    }
    printf("\n");
}
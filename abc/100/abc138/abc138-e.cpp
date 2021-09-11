#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,m,ans=0,a[100001][26];
char s[100010],t[100010];
int main(){
    scanf("%s",s);
    scanf("%s",t);
    n=strlen(s);
    m=strlen(t);
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            a[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        a[i][s[i]-'a']=(i)%n;
        for(int j=i-1;s[(j+n*n)%n]!=s[i];j--){
            a[(j+n*n)%n][s[i]-'a']=(i)%n;
        }
    }
    ll p=-1;
    for(int i=0;i<m;i++){
        p++;
        p%=n;
        ans++;
        if(a[p][t[i]-'a']==-1){
            printf("-1\n");
            return 0;
        }
        ans+=(n+a[p][t[i]-'a']-p)%n;
        p=a[p][t[i]-'a'];
    }
    printf("%lld\n",ans);
}
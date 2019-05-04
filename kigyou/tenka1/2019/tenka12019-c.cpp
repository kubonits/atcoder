#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n,dpw[200011]={},dpb[200011]={},ans=2001000;
    char s[200100];
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        dpw[i+1]=dpw[i];
        if(s[i]=='#'){
            dpw[i+1]++;
        }
    }
    for(int i=n-1;i>=0;i--){
        dpb[n-i]=dpb[n-1-i];
        if(s[i]=='.'){
            dpb[n-i]++;
        }
    }
    for(int i=0;i<=n;i++){
        ans=min(ans,dpb[i]+dpw[n-i]);
    }
    printf("%d\n",ans);
}
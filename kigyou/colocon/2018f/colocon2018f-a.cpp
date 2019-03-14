#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    long long n,m,cnt=0,ans=0,b=0;
    char s[100010];
    scanf("%d",&n);
    scanf("%s",s);
    m=strlen(s);
    for(long long i=0;i<m;i++){
        if(s[i]=='A'){
            cnt++;
            ans+=cnt;
        }
        else{
            cnt=0;
        }
    }
    if(m==cnt){
        ans=(n*m+1)*(n*m)/2;
    }
    else{
        for(long long i=0;i<m;i++){
            if(s[i]=='A'){
                cnt++;
                b+=cnt;
            }
            else{
                cnt=0;
            }
        }
        ans+=b*(n-1);
    }
    printf("%lld\n",ans);
}
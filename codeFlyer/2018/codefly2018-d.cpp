#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[2001][2001],b[2001],c[2001],d;
char s[1000][1001];
int main(){
    ll h,w,n,m,ans=0;
    scanf("%lld %lld",&h,&w);
    scanf("%lld %lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='#'){
                a[i][j]++;
                a[min(i+n+1,h-n+i+1)][min(j+m,w-m+j)+1]++;
                a[i][min(j+m,w-m+j)+1]--;
                a[min(i+n+1,h-n+i+1)][j]--;
                b[i]++;
                b[min(i+n,h-n+i)+1]--;
                c[j]++;
                c[min(j+m,w-m+j)+1]--;
                d++;
            }
        }
    }
    for(int i=0;i<2*h;i++){
        for(int j=0;j<2*w;j++){
            a[i+1][j]+=a[i][j];
        }
    }
    for(int i=0;i<min(2*n,h);i++){
        for(int j=0;j<min(2*m,w);j++){
            a[i][j+1]+=a[i][j];
            if(a[i][j]>0){
                ans++;
            }
        }
    }
    for(int i=0;i<2*n;i++){
        b[i+1]+=b[i];
        if(b[i]>0){
            ans+=max(0LL,h-2LL*n);
        }
    }
    for(int i=0;i<2*m;i++){
        c[i+1]+=c[i];
        if(c[i]>0){
            ans+=max(0LL,w-2LL*m);
        }
    }
    if(d>0&&(h-2LL*n)>0&&(w-2LL*m)>0){
        ans+=max(0LL,(h-2LL*n)*(w-2LL*m));
    }
    printf("%lld\n",ans);
}
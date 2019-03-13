#include<cstdio>
#include<cmath>
typedef long long ll;
using namespace std;
int main(){
    ll n,x[1000],y[1000],two[35],sum[36],a,b,c,d;
    char s[36];
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&x[i],&y[i]);
    }
    for(int i=1;i<n;i++){
        a=abs(x[i]+y[i]);
        b=abs(x[0]+y[0]);
        if(a%2!=b%2){
            printf("-1\n");
            return 0;
        }
    }
    if((x[0]+y[0])%2){
        two[0]=1;
        for(int i=1;i<35;i++){
            two[i]=2*two[i-1];
        }
    }
    else{
        two[0]=two[1]=1;
        for(int i=2;i<35;i++){
            two[i]=2*two[i-1];
        }
    }
    sum[0]=0;
    for(int i=0;i<35;i++){
        sum[i+1]=sum[i]+two[i];
    }
    s[35]='\0';
    printf("35\n");
    for(int i=0;i<35;i++){
        printf("%lld ",two[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=34;j>=0;j--){
            a=abs(x[i]+two[j])+abs(y[i]);
            b=abs(x[i]-two[j])+abs(y[i]);
            c=abs(x[i])+abs(y[i]-two[j]);
            d=abs(x[i])+abs(y[i]+two[j]);
            if(a<=sum[j]){
                s[j]='L';
                x[i]+=two[j];
            }
            else if(b<=sum[j]){
                s[j]='R';
                x[i]-=two[j];
            }
            else if(c<=sum[j]){
                s[j]='U';
                y[i]-=two[j];
            }
            else if(d<=sum[j]){
                s[j]='D';
                y[i]+=two[j];
            }
        }
        printf("%s\n",s);
    }
}